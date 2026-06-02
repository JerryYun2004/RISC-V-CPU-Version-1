`timescale 1ns/1ps

import cpu_pkg::*;

module decoder (
    input  logic [31:0]       instr_i,
    output decoded_instr_t    decoded_o
);

  localparam logic [6:0] OPCODE_LUI    = 7'b0110111;
  localparam logic [6:0] OPCODE_AUIPC  = 7'b0010111;
  localparam logic [6:0] OPCODE_JAL    = 7'b1101111;
  localparam logic [6:0] OPCODE_JALR   = 7'b1100111;
  localparam logic [6:0] OPCODE_BRANCH = 7'b1100011;
  localparam logic [6:0] OPCODE_LOAD   = 7'b0000011;
  localparam logic [6:0] OPCODE_STORE  = 7'b0100011;
  localparam logic [6:0] OPCODE_OP_IMM = 7'b0010011;
  localparam logic [6:0] OPCODE_OP     = 7'b0110011;
  localparam logic [6:0] OPCODE_MISC   = 7'b0001111; // FENCE treated as NOP in this baseline.

  logic [6:0] opcode;
  logic [2:0] funct3;
  logic [6:0] funct7;

  assign opcode = instr_i[6:0];
  assign funct3 = instr_i[14:12];
  assign funct7 = instr_i[31:25];

  always_comb begin
    decoded_o = '0;

    decoded_o.valid    = 1'b1;
    decoded_o.illegal  = 1'b0;
    decoded_o.rs1      = instr_i[19:15];
    decoded_o.rs2      = instr_i[24:20];
    decoded_o.rd       = instr_i[11:7];
    decoded_o.funct3   = funct3;
    decoded_o.alu_op   = ALU_ADD;
    decoded_o.imm_type = IMM_NONE;
    decoded_o.wb_sel   = WB_NONE;

    unique case (opcode)
      OPCODE_LUI: begin
        decoded_o.reg_write = 1'b1;
        decoded_o.use_imm   = 1'b1;
        decoded_o.imm_type  = IMM_U;
        decoded_o.alu_op    = ALU_COPY_B;
        decoded_o.wb_sel    = WB_ALU;
      end

      OPCODE_AUIPC: begin
        decoded_o.reg_write = 1'b1;
        decoded_o.use_pc    = 1'b1;
        decoded_o.use_imm   = 1'b1;
        decoded_o.imm_type  = IMM_U;
        decoded_o.alu_op    = ALU_ADD;
        decoded_o.wb_sel    = WB_ALU;
      end

      OPCODE_JAL: begin
        decoded_o.reg_write = 1'b1;
        decoded_o.jump      = 1'b1;
        decoded_o.imm_type  = IMM_J;
        decoded_o.wb_sel    = WB_PC4;
      end

      OPCODE_JALR: begin
        decoded_o.reg_write = 1'b1;
        decoded_o.jump      = 1'b1;
        decoded_o.jalr      = 1'b1;
        decoded_o.use_imm   = 1'b1;
        decoded_o.imm_type  = IMM_I;
        decoded_o.wb_sel    = WB_PC4;
        decoded_o.illegal   = (funct3 != 3'b000);
      end

      OPCODE_BRANCH: begin
        decoded_o.branch    = 1'b1;
        decoded_o.imm_type  = IMM_B;
        unique case (funct3)
          3'b000, 3'b001, 3'b100, 3'b101, 3'b110, 3'b111: decoded_o.illegal = 1'b0;
          default: decoded_o.illegal = 1'b1;
        endcase
      end

      OPCODE_LOAD: begin
        decoded_o.reg_write = 1'b1;
        decoded_o.mem_read  = 1'b1;
        decoded_o.use_imm   = 1'b1;
        decoded_o.imm_type  = IMM_I;
        decoded_o.alu_op    = ALU_ADD;
        decoded_o.wb_sel    = WB_MEM;
        unique case (funct3)
          3'b000, 3'b001, 3'b010, 3'b100, 3'b101: decoded_o.illegal = 1'b0;
          default: decoded_o.illegal = 1'b1;
        endcase
      end

      OPCODE_STORE: begin
        decoded_o.mem_write = 1'b1;
        decoded_o.use_imm   = 1'b1;
        decoded_o.imm_type  = IMM_S;
        decoded_o.alu_op    = ALU_ADD;
        unique case (funct3)
          3'b000, 3'b001, 3'b010: decoded_o.illegal = 1'b0;
          default: decoded_o.illegal = 1'b1;
        endcase
      end

      OPCODE_OP_IMM: begin
        decoded_o.reg_write = 1'b1;
        decoded_o.use_imm   = 1'b1;
        decoded_o.imm_type  = IMM_I;
        decoded_o.wb_sel    = WB_ALU;

        unique case (funct3)
          3'b000: decoded_o.alu_op = ALU_ADD;  // ADDI
          3'b010: decoded_o.alu_op = ALU_SLT;  // SLTI
          3'b011: decoded_o.alu_op = ALU_SLTU; // SLTIU
          3'b100: decoded_o.alu_op = ALU_XOR;  // XORI
          3'b110: decoded_o.alu_op = ALU_OR;   // ORI
          3'b111: decoded_o.alu_op = ALU_AND;  // ANDI
          3'b001: begin                         // SLLI
            decoded_o.alu_op  = ALU_SLL;
            decoded_o.illegal = (funct7 != 7'b0000000);
          end
          3'b101: begin
            unique case (funct7)
              7'b0000000: decoded_o.alu_op = ALU_SRL; // SRLI
              7'b0100000: decoded_o.alu_op = ALU_SRA; // SRAI
              default: begin
                decoded_o.alu_op  = ALU_SRL;
                decoded_o.illegal = 1'b1;
              end
            endcase
          end
          default: decoded_o.illegal = 1'b1;
        endcase
      end

      OPCODE_OP: begin
        decoded_o.reg_write = 1'b1;
        decoded_o.wb_sel    = WB_ALU;

        unique case ({funct7, funct3})
          {7'b0000000, 3'b000}: decoded_o.alu_op = ALU_ADD;
          {7'b0100000, 3'b000}: decoded_o.alu_op = ALU_SUB;
          {7'b0000000, 3'b001}: decoded_o.alu_op = ALU_SLL;
          {7'b0000000, 3'b010}: decoded_o.alu_op = ALU_SLT;
          {7'b0000000, 3'b011}: decoded_o.alu_op = ALU_SLTU;
          {7'b0000000, 3'b100}: decoded_o.alu_op = ALU_XOR;
          {7'b0000000, 3'b101}: decoded_o.alu_op = ALU_SRL;
          {7'b0100000, 3'b101}: decoded_o.alu_op = ALU_SRA;
          {7'b0000000, 3'b110}: decoded_o.alu_op = ALU_OR;
          {7'b0000000, 3'b111}: decoded_o.alu_op = ALU_AND;
          default: begin
            decoded_o.alu_op  = ALU_ADD;
            decoded_o.illegal = 1'b1;
          end
        endcase
      end

      OPCODE_MISC: begin
        // FENCE/FENCE.I are treated as NOP for this simple uncached CPU.
        decoded_o.reg_write = 1'b0;
        decoded_o.wb_sel    = WB_NONE;
      end

      default: begin
        decoded_o.illegal = 1'b1;
        decoded_o.valid   = 1'b0;
      end
    endcase
  end

endmodule
