`timescale 1ns/1ps

// -----------------------------------------------------------------------------
// tb_cpu_top + simple memory/MMIO model
// -----------------------------------------------------------------------------
// This file intentionally contains both:
//   1. simple_mem: a tiny SRAM + debug/UART MMIO bus target
//   2. tb_cpu_top: a Verilator-friendly wrapper around cpu_top + simple_mem
//
// Bus behavior:
// - Always grants requests immediately.
// - Returns rvalid one cycle after a granted request.
// - Uses rvalid as completion for both reads and writes.
//
// Memory map used by this verification harness:
//   0x0000_0000 - 0x0000_FFFF   SRAM/program/data memory
//   0x1000_0000                 UART TXDATA, write low byte to print char
//   0x3000_0000                 DONE register, write nonzero to finish sim
//   0x3000_0004                 RESULT_CODE register
// -----------------------------------------------------------------------------

module simple_mem #(
    parameter int unsigned MEM_WORDS = 16 * 1024
) (
    input  logic        clk_i,
    input  logic        rst_ni,

    input  logic        bus_req_i,
    input  logic        bus_we_i,
    input  logic [31:0] bus_addr_i,
    input  logic [31:0] bus_wdata_i,
    input  logic [3:0]  bus_be_i,
    output logic        bus_gnt_o,
    output logic        bus_rvalid_o,
    output logic [31:0] bus_rdata_o,

    output logic        done_o,
    output logic [31:0] result_code_o
);

  localparam logic [31:0] UART_TXDATA_ADDR = 32'h1000_0000;
  localparam logic [31:0] DBG_DONE_ADDR    = 32'h3000_0000;
  localparam logic [31:0] DBG_CODE_ADDR    = 32'h3000_0004;

  logic [31:0] mem [0:MEM_WORDS-1];

  logic        pending_q;
  logic [31:0] rdata_q;

  string hex_file;
  int unsigned word_idx;

  assign bus_gnt_o    = bus_req_i;
  assign bus_rvalid_o = pending_q;
  assign bus_rdata_o  = rdata_q;

  function automatic logic addr_is_sram(input logic [31:0] addr);
    addr_is_sram = (addr[31:16] == 16'h0000) && (addr[15:2] < MEM_WORDS);
  endfunction

  function automatic logic [31:0] read_word(input logic [31:0] addr);
    logic [31:0] data;
    begin
      data = 32'h0000_0000;
      if (addr_is_sram(addr)) begin
        data = mem[addr[15:2]];
      end else if (addr == DBG_DONE_ADDR) begin
        data = {31'b0, done_o};
      end else if (addr == DBG_CODE_ADDR) begin
        data = result_code_o;
      end else begin
        $display("[MEM-WARN] Read from unmapped address %08x", addr);
        data = 32'hBAD0_BAD0;
      end
      read_word = data;
    end
  endfunction

  task automatic write_word(
      input logic [31:0] addr,
      input logic [31:0] wdata,
      input logic [3:0]  be
  );
    begin
      if (addr_is_sram(addr)) begin
        word_idx = addr[15:2];
        if (be[0]) mem[word_idx][7:0]   <= wdata[7:0];
        if (be[1]) mem[word_idx][15:8]  <= wdata[15:8];
        if (be[2]) mem[word_idx][23:16] <= wdata[23:16];
        if (be[3]) mem[word_idx][31:24] <= wdata[31:24];
      end else if (addr == UART_TXDATA_ADDR) begin
        $write("%c", wdata[7:0]);
      end else if (addr == DBG_DONE_ADDR) begin
        done_o <= (wdata != 32'h0000_0000);
        $display("[DBG] DONE <= %08x", wdata);
      end else if (addr == DBG_CODE_ADDR) begin
        result_code_o <= wdata;
        $display("[DBG] RESULT_CODE <= %08x", wdata);
      end else begin
        $display("[MEM-WARN] Write to unmapped address %08x data=%08x be=%b", addr, wdata, be);
      end
    end
  endtask

  initial begin
    for (int i = 0; i < MEM_WORDS; i++) begin
      mem[i] = 32'h0000_0013; // ADDI x0, x0, 0 / NOP
    end

    hex_file = "programs/test_addi.hex";
    if ($value$plusargs("hex=%s", hex_file)) begin
      // plusarg overrides default
    end

    $display("[MEM] Loading program hex: %s", hex_file);
    $readmemh(hex_file, mem);
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      pending_q     <= 1'b0;
      rdata_q       <= 32'h0000_0000;
      done_o        <= 1'b0;
      result_code_o <= 32'h0000_0000;
    end else begin
      // Capture and service a newly granted request. The rvalid response is
      // asserted on the following cycle by pending_q. For reads, rdata_q is
      // prepared immediately so it is stable for the response cycle.
      pending_q <= bus_req_i && bus_gnt_o;

      if (bus_req_i && bus_gnt_o) begin
        if (bus_we_i) begin
          write_word(bus_addr_i, bus_wdata_i, bus_be_i);
          rdata_q <= 32'h0000_0000;
        end else begin
          rdata_q <= read_word(bus_addr_i);
        end
      end
    end
  end

endmodule

module tb_cpu_top (
    input  logic        clk_i,
    input  logic        rst_ni,
    output logic        done_o,
    output logic [31:0] result_code_o,
    output logic        trap_o,
    output logic [31:0] pc_o
);

  logic        bus_req;
  logic        bus_we;
  logic [31:0] bus_addr;
  logic [31:0] bus_wdata;
  logic [3:0]  bus_be;
  logic        bus_gnt;
  logic        bus_rvalid;
  logic [31:0] bus_rdata;

  cpu_top #(
      .RESET_PC (32'h0000_0000),
      .TRACE_EN (1'b1)
  ) u_cpu (
      .clk_i        (clk_i),
      .rst_ni       (rst_ni),
      .bus_req_o    (bus_req),
      .bus_we_o     (bus_we),
      .bus_addr_o   (bus_addr),
      .bus_wdata_o  (bus_wdata),
      .bus_be_o     (bus_be),
      .bus_gnt_i    (bus_gnt),
      .bus_rvalid_i (bus_rvalid),
      .bus_rdata_i  (bus_rdata),
      .trap_o       (trap_o),
      .pc_o         (pc_o)
  );

  simple_mem u_mem (
      .clk_i         (clk_i),
      .rst_ni        (rst_ni),
      .bus_req_i     (bus_req),
      .bus_we_i      (bus_we),
      .bus_addr_i    (bus_addr),
      .bus_wdata_i   (bus_wdata),
      .bus_be_i      (bus_be),
      .bus_gnt_o     (bus_gnt),
      .bus_rvalid_o  (bus_rvalid),
      .bus_rdata_o   (bus_rdata),
      .done_o        (done_o),
      .result_code_o (result_code_o)
  );

endmodule
