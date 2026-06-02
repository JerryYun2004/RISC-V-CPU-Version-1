`timescale 1ns/1ps

module branch_unit (
    input  logic [31:0] rs1_i,
    input  logic [31:0] rs2_i,
    input  logic [2:0]  funct3_i,
    output logic        branch_taken_o
);

  always_comb begin
    unique case (funct3_i)
      3'b000: branch_taken_o = (rs1_i == rs2_i);                    // BEQ
      3'b001: branch_taken_o = (rs1_i != rs2_i);                    // BNE
      3'b100: branch_taken_o = ($signed(rs1_i) <  $signed(rs2_i));  // BLT
      3'b101: branch_taken_o = ($signed(rs1_i) >= $signed(rs2_i));  // BGE
      3'b110: branch_taken_o = (rs1_i <  rs2_i);                    // BLTU
      3'b111: branch_taken_o = (rs1_i >= rs2_i);                    // BGEU
      default: branch_taken_o = 1'b0;
    endcase
  end

endmodule
