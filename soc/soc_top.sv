`timescale 1ns/1ps

import soc_pkg::*;

// -----------------------------------------------------------------------------
// soc_top
// -----------------------------------------------------------------------------
// Minimal SoC wrapper around the custom RV32I CPU.
//
// Blocks:
//   cpu_top     : existing CPU core
//   soc_sram    : SRAM/program/data memory
//   mmio_debug  : DONE, RESULT_CODE, and UART-style debug output
//
// Bus behavior exposed to the CPU:
//   - grant is immediate when bus_req_o is asserted
//   - rvalid is returned one cycle after request
//   - rvalid is used for both read data and write completion
// -----------------------------------------------------------------------------
module soc_top #(
    parameter logic [31:0] RESET_PC = 32'h0000_0000,
    parameter bit          TRACE_EN = 1'b0
) (
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

  logic        sram_hit;
  logic [31:0] sram_rdata;
  logic        sram_write;

  logic        mmio_hit;
  logic [31:0] mmio_rdata;
  logic        mmio_write;

  logic        pending_q;
  logic [31:0] rdata_q;
  logic [31:0] response_rdata;

  assign bus_gnt    = bus_req;
  assign bus_rvalid = pending_q;
  assign bus_rdata  = rdata_q;

  cpu_top #(
      .RESET_PC (RESET_PC),
      .TRACE_EN (TRACE_EN)
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

  assign sram_write = bus_req && bus_gnt && bus_we && sram_hit;
  assign mmio_write = bus_req && bus_gnt && bus_we && mmio_hit;

  soc_sram #(
      .MEM_WORDS (soc_pkg::SRAM_WORDS)
  ) u_sram (
      .clk_i   (clk_i),
      .rst_ni  (rst_ni),
      .write_i (sram_write),
      .addr_i  (bus_addr),
      .wdata_i (bus_wdata),
      .be_i    (bus_be),
      .hit_o   (sram_hit),
      .rdata_o (sram_rdata)
  );

  mmio_debug u_mmio_debug (
      .clk_i         (clk_i),
      .rst_ni        (rst_ni),
      .write_i       (mmio_write),
      .addr_i        (bus_addr),
      .wdata_i       (bus_wdata),
      .be_i          (bus_be),
      .hit_o         (mmio_hit),
      .rdata_o       (mmio_rdata),
      .done_o        (done_o),
      .result_code_o (result_code_o)
  );

  always_comb begin
    if (sram_hit) begin
      response_rdata = sram_rdata;
    end else if (mmio_hit) begin
      response_rdata = mmio_rdata;
    end else begin
      response_rdata = 32'hBAD0_BAD0;
    end
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      pending_q <= 1'b0;
      rdata_q   <= 32'h0000_0000;
    end else begin
      pending_q <= bus_req && bus_gnt;

      if (bus_req && bus_gnt) begin
        if (bus_we) begin
          rdata_q <= 32'h0000_0000;
          if (!sram_hit && !mmio_hit) begin
            $display("[SOC-WARN] Write to unmapped address %08x data=%08x be=%b", bus_addr, bus_wdata, bus_be);
          end
        end else begin
          rdata_q <= response_rdata;
          if (!sram_hit && !mmio_hit) begin
            $display("[SOC-WARN] Read from unmapped address %08x", bus_addr);
          end
        end
      end
    end
  end

endmodule
