// Copyright (c) 2026
// Simple custom RV32I CPU package.
// Baseline target: multi-cycle RV32I, no CSRs, no interrupts, no cache.

package cpu_pkg;

  parameter int XLEN = 32;
  parameter int REG_ADDR_W = 5;

  typedef enum logic [3:0] {
    ALU_ADD    = 4'd0,
    ALU_SUB    = 4'd1,
    ALU_AND    = 4'd2,
    ALU_OR     = 4'd3,
    ALU_XOR    = 4'd4,
    ALU_SLL    = 4'd5,
    ALU_SRL    = 4'd6,
    ALU_SRA    = 4'd7,
    ALU_SLT    = 4'd8,
    ALU_SLTU   = 4'd9,
    ALU_COPY_B = 4'd10
  } alu_op_e;

  typedef enum logic [2:0] {
    IMM_NONE = 3'd0,
    IMM_I    = 3'd1,
    IMM_S    = 3'd2,
    IMM_B    = 3'd3,
    IMM_U    = 3'd4,
    IMM_J    = 3'd5
  } imm_type_e;

  typedef enum logic [1:0] {
    WB_ALU  = 2'd0,
    WB_MEM  = 2'd1,
    WB_PC4  = 2'd2,
    WB_NONE = 2'd3
  } wb_sel_e;

  typedef enum logic [3:0] {
    CPU_S_RESET      = 4'd0,
    CPU_S_FETCH_REQ  = 4'd1,
    CPU_S_FETCH_WAIT = 4'd2,
    CPU_S_DECODE     = 4'd3,
    CPU_S_EXECUTE    = 4'd4,
    CPU_S_MEM_REQ    = 4'd5,
    CPU_S_MEM_WAIT   = 4'd6,
    CPU_S_WRITEBACK  = 4'd7,
    CPU_S_TRAP       = 4'd8
  } cpu_state_e;

  typedef struct packed {
    logic        valid;
    logic        illegal;

    logic        reg_write;
    logic        mem_read;
    logic        mem_write;
    logic        branch;
    logic        jump;
    logic        jalr;

    logic        use_imm;
    logic        use_pc;

    logic [2:0]  funct3;
    logic [4:0]  rs1;
    logic [4:0]  rs2;
    logic [4:0]  rd;

    alu_op_e     alu_op;
    imm_type_e   imm_type;
    wb_sel_e     wb_sel;
  } decoded_instr_t;

endpackage
