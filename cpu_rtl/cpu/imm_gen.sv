`timescale 1ns/1ps

import cpu_pkg::*;

module imm_gen (
    input  logic [31:0] instr_i,
    input  imm_type_e   imm_type_i,
    output logic [31:0] imm_o
);

  logic [31:0] imm_i_type;
  logic [31:0] imm_s_type;
  logic [31:0] imm_b_type;
  logic [31:0] imm_u_type;
  logic [31:0] imm_j_type;

  assign imm_i_type = {{20{instr_i[31]}}, instr_i[31:20]};
  assign imm_s_type = {{20{instr_i[31]}}, instr_i[31:25], instr_i[11:7]};
  assign imm_b_type = {{19{instr_i[31]}}, instr_i[31], instr_i[7],
                       instr_i[30:25], instr_i[11:8], 1'b0};
  assign imm_u_type = {instr_i[31:12], 12'b0};
  assign imm_j_type = {{11{instr_i[31]}}, instr_i[31], instr_i[19:12],
                       instr_i[20], instr_i[30:21], 1'b0};

  always_comb begin
    unique case (imm_type_i)
      IMM_I:    imm_o = imm_i_type;
      IMM_S:    imm_o = imm_s_type;
      IMM_B:    imm_o = imm_b_type;
      IMM_U:    imm_o = imm_u_type;
      IMM_J:    imm_o = imm_j_type;
      default:  imm_o = 32'h0000_0000;
    endcase
  end

endmodule
