`timescale 1ns/1ps

module regfile (
    input  logic        clk_i,
    input  logic        rst_ni,

    input  logic [4:0]  rs1_addr_i,
    input  logic [4:0]  rs2_addr_i,
    output logic [31:0] rs1_rdata_o,
    output logic [31:0] rs2_rdata_o,

    input  logic [4:0]  rd_addr_i,
    input  logic [31:0] rd_wdata_i,
    input  logic        rd_we_i
);

  logic [31:0] regs_q [31:0];

  // Asynchronous reads keep the multi-cycle CPU simple.
  // x0 is hardwired to zero.
  assign rs1_rdata_o = (rs1_addr_i == 5'd0) ? 32'h0000_0000 : regs_q[rs1_addr_i];
  assign rs2_rdata_o = (rs2_addr_i == 5'd0) ? 32'h0000_0000 : regs_q[rs2_addr_i];

  integer i;
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      for (i = 0; i < 32; i++) begin
        regs_q[i] <= 32'h0000_0000;
      end
    end else begin
      if (rd_we_i && (rd_addr_i != 5'd0)) begin
        regs_q[rd_addr_i] <= rd_wdata_i;
      end
      // Defensive write: keep x0 zero even if synthesis/simulation changes elsewhere.
      regs_q[0] <= 32'h0000_0000;
    end
  end

endmodule
