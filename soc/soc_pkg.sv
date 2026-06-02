`timescale 1ns/1ps

package soc_pkg;

  // ---------------------------------------------------------------------------
  // Simple SoC address map
  // ---------------------------------------------------------------------------
  // SRAM/program/data memory:
  //   0x0000_0000 - 0x0000_FFFF
  //
  // MMIO/debug region:
  //   0x1000_0000   UART TXDATA, write low byte to print a character
  //   0x3000_0000   DONE register, write nonzero to terminate simulation
  //   0x3000_0004   RESULT_CODE register
  // ---------------------------------------------------------------------------

  localparam logic [31:0] SRAM_BASE_ADDR       = 32'h0000_0000;
  localparam int unsigned SRAM_SIZE_BYTES      = 64 * 1024;
  localparam int unsigned SRAM_WORDS           = SRAM_SIZE_BYTES / 4;

  localparam logic [31:0] UART_TXDATA_ADDR     = 32'h1000_0000;
  localparam logic [31:0] DBG_DONE_ADDR        = 32'h3000_0000;
  localparam logic [31:0] DBG_RESULT_CODE_ADDR = 32'h3000_0004;

endpackage
