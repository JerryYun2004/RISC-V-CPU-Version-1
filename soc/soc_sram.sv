`timescale 1ns/1ps

import soc_pkg::*;

// -----------------------------------------------------------------------------
// soc_sram
// -----------------------------------------------------------------------------
// Small word-addressed SRAM used by the simple SoC wrapper.
// - Program/data hex is loaded through +hex=<file>.
// - Reads are combinational from the current address.
// - Writes happen on the rising clock edge when write_i is asserted.
// - Byte enables are supported for SB/SH/SW tests.
// -----------------------------------------------------------------------------
module soc_sram #(
    parameter int unsigned MEM_WORDS = soc_pkg::SRAM_WORDS
) (
    input  logic        clk_i,
    input  logic        rst_ni,

    input  logic        write_i,
    input  logic [31:0] addr_i,
    input  logic [31:0] wdata_i,
    input  logic [3:0]  be_i,

    output logic        hit_o,
    output logic [31:0] rdata_o
);

  logic [31:0] mem [0:MEM_WORDS-1];
  string hex_file;

  function automatic logic addr_is_sram(input logic [31:0] addr);
    logic [31:0] word_index;
    begin
      word_index   = {18'b0, addr[15:2]};
      addr_is_sram = (addr[31:16] == 16'h0000) && (word_index < MEM_WORDS);
    end
  endfunction

  assign hit_o = addr_is_sram(addr_i);

  always_comb begin
    if (hit_o) begin
      rdata_o = mem[addr_i[15:2]];
    end else begin
      rdata_o = 32'hBAD0_BAD0;
    end
  end

  initial begin
    for (int i = 0; i < MEM_WORDS; i++) begin
      mem[i] = 32'h0000_0013; // ADDI x0, x0, 0 / NOP
    end

    hex_file = "programs/test_soc_smoke.hex";
    if ($value$plusargs("hex=%s", hex_file)) begin
      // plusarg overrides default
    end

    $display("[SRAM] Loading program hex: %s", hex_file);
    $readmemh(hex_file, mem);
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      // Memory contents are initialized in the initial block and intentionally
      // not reset here.
    end else if (write_i && hit_o) begin
      if (be_i[0]) mem[addr_i[15:2]][7:0]   <= wdata_i[7:0];
      if (be_i[1]) mem[addr_i[15:2]][15:8]  <= wdata_i[15:8];
      if (be_i[2]) mem[addr_i[15:2]][23:16] <= wdata_i[23:16];
      if (be_i[3]) mem[addr_i[15:2]][31:24] <= wdata_i[31:24];
    end
  end

endmodule
