`timescale 1ns/1ps

import soc_pkg::*;

// -----------------------------------------------------------------------------
// mmio_debug
// -----------------------------------------------------------------------------
// Minimal debug MMIO block for simulation bring-up.
//
// Address map:
//   0x1000_0000   UART TXDATA, write low byte to print a character
//   0x3000_0000   DONE register, write nonzero to terminate simulation
//   0x3000_0004   RESULT_CODE register
// -----------------------------------------------------------------------------
module mmio_debug (
    input  logic        clk_i,
    input  logic        rst_ni,

    input  logic        write_i,
    input  logic [31:0] addr_i,
    input  logic [31:0] wdata_i,
    input  logic [3:0]  be_i,

    output logic        hit_o,
    output logic [31:0] rdata_o,
    output logic        done_o,
    output logic [31:0] result_code_o
);

  assign hit_o = (addr_i == UART_TXDATA_ADDR)     ||
                 (addr_i == DBG_DONE_ADDR)        ||
                 (addr_i == DBG_RESULT_CODE_ADDR);

  always_comb begin
    unique case (addr_i)
      DBG_DONE_ADDR:        rdata_o = {31'b0, done_o};
      DBG_RESULT_CODE_ADDR: rdata_o = result_code_o;
      UART_TXDATA_ADDR:     rdata_o = 32'h0000_0000;
      default:              rdata_o = 32'hBAD0_BAD0;
    endcase
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      done_o        <= 1'b0;
      result_code_o <= 32'h0000_0000;
    end else if (write_i && hit_o) begin
      unique case (addr_i)
        UART_TXDATA_ADDR: begin
          if (be_i[0]) begin
            $write("%c", wdata_i[7:0]);
          end
        end

        DBG_DONE_ADDR: begin
          done_o <= (wdata_i != 32'h0000_0000);
          $display("[MMIO] DONE <= %08x", wdata_i);
        end

        DBG_RESULT_CODE_ADDR: begin
          result_code_o <= wdata_i;
          $display("[MMIO] RESULT_CODE <= %08x", wdata_i);
        end

        default: begin
          // hit_o prevents this branch in normal use.
        end
      endcase
    end
  end

endmodule
