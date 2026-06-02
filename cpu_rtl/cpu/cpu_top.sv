`timescale 1ns/1ps

import cpu_pkg::*;

// -----------------------------------------------------------------------------
// cpu_top
// -----------------------------------------------------------------------------
// Baseline custom RV32I CPU.
// - Multi-cycle FSM
// - One unified external bus for instruction fetch, load/store, and MMIO
// - One outstanding bus transaction at a time
// - No CSRs, no interrupts, no cache
// - Misaligned loads/stores trap
//
// Bus contract:
// - CPU asserts bus_req_o until bus_gnt_i is seen.
// - For reads and writes, completion is indicated by bus_rvalid_i.
// - For reads, bus_rdata_i is valid when bus_rvalid_i is high.
// - For writes, bus_rvalid_i is used as a write-response/done signal.
// -----------------------------------------------------------------------------
module cpu_top #(
    parameter logic [31:0] RESET_PC = 32'h0000_0000,
    parameter bit          TRACE_EN = 1'b0
) (
    input  logic        clk_i,
    input  logic        rst_ni,

    output logic        bus_req_o,
    output logic        bus_we_o,
    output logic [31:0] bus_addr_o,
    output logic [31:0] bus_wdata_o,
    output logic [3:0]  bus_be_o,
    input  logic        bus_gnt_i,
    input  logic        bus_rvalid_i,
    input  logic [31:0] bus_rdata_i,

    output logic        trap_o,
    output logic [31:0] pc_o
);

  // Architectural/control registers.
  logic [31:0] pc_q;
  logic [31:0] instr_q;
  logic [31:0] alu_result_q;
  logic [31:0] load_result_q;
  logic [31:0] mem_addr_q;
  logic [31:0] mem_wdata_q;
  logic [3:0]  mem_be_q;
  logic [31:0] pc_next_q;

  decoded_instr_t decoded;
  decoded_instr_t decoded_q;
  cpu_state_e     state;

  logic [31:0] imm;
  logic [31:0] rs1_val;
  logic [31:0] rs2_val;
  logic [31:0] alu_a;
  logic [31:0] alu_b;
  logic [31:0] alu_result;
  logic        branch_taken;

  logic [3:0]  lsu_be;
  logic [31:0] lsu_store_wdata;
  logic [31:0] lsu_load_data;
  logic        lsu_misaligned;
  logic        mem_fault;

  logic        fetch_req;
  logic        instr_we;
  logic        execute_we;
  logic        mem_req;
  logic        load_we;
  logic        reg_we;
  logic        pc_we;

  logic [31:0] wb_data;
  logic [31:0] pc_plus4;
  logic [31:0] branch_target;
  logic [31:0] jal_target;
  logic [31:0] jalr_target;
  logic [31:0] pc_next_calc;

  assign pc_o     = pc_q;
  assign pc_plus4 = pc_q + 32'd4;

  decoder u_decoder (
      .instr_i   (instr_q),
      .decoded_o (decoded)
  );

  imm_gen u_imm_gen (
      .instr_i    (instr_q),
      .imm_type_i (decoded.imm_type),
      .imm_o      (imm)
  );

  regfile u_regfile (
      .clk_i       (clk_i),
      .rst_ni      (rst_ni),
      .rs1_addr_i  (decoded.rs1),
      .rs2_addr_i  (decoded.rs2),
      .rs1_rdata_o (rs1_val),
      .rs2_rdata_o (rs2_val),
      .rd_addr_i   (decoded_q.rd),
      .rd_wdata_i  (wb_data),
      .rd_we_i     (reg_we)
  );

  assign alu_a = decoded.use_pc  ? pc_q : rs1_val;
  assign alu_b = decoded.use_imm ? imm  : rs2_val;

  alu u_alu (
      .a_i      (alu_a),
      .b_i      (alu_b),
      .op_i     (decoded.alu_op),
      .result_o (alu_result)
  );

  branch_unit u_branch_unit (
      .rs1_i           (rs1_val),
      .rs2_i           (rs2_val),
      .funct3_i        (decoded.funct3),
      .branch_taken_o  (branch_taken)
  );

  lsu u_lsu (
      .addr_i         (alu_result),
      .store_data_i   (rs2_val),
      .load_rdata_i   (bus_rdata_i),
      .funct3_i       (decoded.funct3),
      .is_load_i      (decoded.mem_read),
      .is_store_i     (decoded.mem_write),
      .be_o           (lsu_be),
      .store_wdata_o  (lsu_store_wdata),
      .load_data_o    (lsu_load_data),
      .misaligned_o   (lsu_misaligned)
  );

  // Instruction fetch must be word-aligned because this baseline has no RV32C.
  assign mem_fault = (execute_we && lsu_misaligned) ||
                     ((state == CPU_S_FETCH_REQ) && (pc_q[1:0] != 2'b00));

  control_fsm u_control_fsm (
      .clk_i        (clk_i),
      .rst_ni       (rst_ni),
      .decoded_i    (decoded),
      .bus_gnt_i    (bus_gnt_i),
      .bus_rvalid_i (bus_rvalid_i),
      .mem_fault_i  (mem_fault),
      .state_o      (state),
      .fetch_req_o  (fetch_req),
      .instr_we_o   (instr_we),
      .execute_we_o (execute_we),
      .mem_req_o    (mem_req),
      .load_we_o    (load_we),
      .reg_we_o     (reg_we),
      .pc_we_o      (pc_we),
      .trap_o       (trap_o)
  );

  // Next PC calculation for the instruction currently in decode/execute.
  assign branch_target = pc_q + imm;
  assign jal_target    = pc_q + imm;
  assign jalr_target   = (rs1_val + imm) & 32'hFFFF_FFFE;

  always_comb begin
    pc_next_calc = pc_plus4;
    if (decoded.branch) begin
      pc_next_calc = branch_taken ? branch_target : pc_plus4;
    end else if (decoded.jump && decoded.jalr) begin
      pc_next_calc = jalr_target;
    end else if (decoded.jump) begin
      pc_next_calc = jal_target;
    end
  end

  // Writeback mux. For JAL/JALR, pc_next_q stores PC+4 as link data through wb_sel=WB_PC4.
  always_comb begin
    unique case (decoded_q.wb_sel)
      WB_ALU:  wb_data = alu_result_q;
      WB_MEM:  wb_data = load_result_q;
      WB_PC4:  wb_data = alu_result_q; // latched as PC+4 for jumps
      default: wb_data = 32'h0000_0000;
    endcase
  end

  // External unified bus mux.
  always_comb begin
    bus_req_o   = 1'b0;
    bus_we_o    = 1'b0;
    bus_addr_o  = 32'h0000_0000;
    bus_wdata_o = 32'h0000_0000;
    bus_be_o    = 4'b0000;

    if (fetch_req) begin
      bus_req_o   = 1'b1;
      bus_we_o    = 1'b0;
      bus_addr_o  = pc_q;
      bus_wdata_o = 32'h0000_0000;
      bus_be_o    = 4'b1111;
    end else if (mem_req) begin
      bus_req_o   = 1'b1;
      bus_we_o    = decoded_q.mem_write;
      bus_addr_o  = mem_addr_q;
      bus_wdata_o = mem_wdata_q;
      bus_be_o    = decoded_q.mem_write ? mem_be_q : 4'b1111;
    end
  end

  // Main sequential state.
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      pc_q          <= RESET_PC;
      instr_q       <= 32'h0000_0013; // ADDI x0, x0, 0
      decoded_q     <= '0;
      alu_result_q  <= 32'h0000_0000;
      load_result_q <= 32'h0000_0000;
      mem_addr_q    <= 32'h0000_0000;
      mem_wdata_q   <= 32'h0000_0000;
      mem_be_q      <= 4'b0000;
      pc_next_q     <= RESET_PC;
    end else begin
      if (instr_we) begin
        instr_q <= bus_rdata_i;
      end

      // Latch decoded instruction after decode, so later states are stable even
      // though instr_q is not changing until the next fetch completes.
      if (state == CPU_S_DECODE) begin
        decoded_q <= decoded;
      end

      if (execute_we) begin
        if (decoded.jump) begin
          // Link value for JAL/JALR writeback.
          alu_result_q <= pc_plus4;
        end else begin
          alu_result_q <= alu_result;
        end

        mem_addr_q   <= alu_result;
        mem_wdata_q  <= lsu_store_wdata;
        mem_be_q     <= lsu_be;
        pc_next_q    <= pc_next_calc;
      end

      if (load_we) begin
        load_result_q <= lsu_load_data;
      end

      if (pc_we) begin
        if ((state == CPU_S_EXECUTE) && (decoded.branch || decoded.jump)) begin
          // Use the current combinational next-PC value.
          // Using pc_next_q here would be one cycle stale.
          pc_q <= pc_next_calc;
        end else begin
          pc_q <= pc_q + 32'd4;
        end
      end

      if (TRACE_EN) begin
        if (instr_we) begin
          $display("[CPU-FETCH] pc=%08x instr=%08x", pc_q, bus_rdata_i);
        end
        if (execute_we) begin
          $display("[CPU-EXEC ] pc=%08x instr=%08x alu=%08x branch=%0d jump=%0d next=%08x",
                   pc_q, instr_q, alu_result, decoded.branch, decoded.jump, pc_next_calc);
        end
        if (reg_we && decoded_q.rd != 5'd0) begin
          $display("[CPU-WB   ] x%0d <= %08x", decoded_q.rd, wb_data);
        end
        if (mem_req) begin
          $display("[CPU-MEM  ] we=%0d addr=%08x wdata=%08x be=%b", bus_we_o, bus_addr_o, bus_wdata_o, bus_be_o);
        end
        if (trap_o) begin
          $display("[CPU-TRAP ] pc=%08x instr=%08x", pc_q, instr_q);
        end
      end
    end
  end

endmodule
