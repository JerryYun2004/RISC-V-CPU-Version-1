`timescale 1ns/1ps

import cpu_pkg::*;

module control_fsm (
    input  logic           clk_i,
    input  logic           rst_ni,

    input  decoded_instr_t decoded_i,
    input  logic           bus_gnt_i,
    input  logic           bus_rvalid_i,
    input  logic           mem_fault_i,

    output cpu_state_e     state_o,

    output logic           fetch_req_o,
    output logic           instr_we_o,
    output logic           execute_we_o,
    output logic           mem_req_o,
    output logic           load_we_o,
    output logic           reg_we_o,
    output logic           pc_we_o,
    output logic           trap_o
);

  cpu_state_e state_q, state_d;

  assign state_o = state_q;
  assign trap_o  = (state_q == CPU_S_TRAP);

  always_comb begin
    state_d = state_q;

    unique case (state_q)
      CPU_S_RESET: begin
        state_d = CPU_S_FETCH_REQ;
      end

      CPU_S_FETCH_REQ: begin
        if (bus_gnt_i) state_d = CPU_S_FETCH_WAIT;
      end

      CPU_S_FETCH_WAIT: begin
        if (bus_rvalid_i) state_d = CPU_S_DECODE;
      end

      CPU_S_DECODE: begin
        if (decoded_i.illegal || !decoded_i.valid) begin
          state_d = CPU_S_TRAP;
        end else begin
          state_d = CPU_S_EXECUTE;
        end
      end

      CPU_S_EXECUTE: begin
        if (mem_fault_i) begin
          state_d = CPU_S_TRAP;
        end else if (decoded_i.mem_read || decoded_i.mem_write) begin
          state_d = CPU_S_MEM_REQ;
        end else if (decoded_i.branch) begin
          state_d = CPU_S_FETCH_REQ;
        end else if (decoded_i.jump) begin
          // JAL/JALR must update PC in EXECUTE, then write PC+4 to rd.
          state_d = decoded_i.reg_write ? CPU_S_WRITEBACK : CPU_S_FETCH_REQ;
        end else if (decoded_i.reg_write) begin
          state_d = CPU_S_WRITEBACK;
        end else begin
          state_d = CPU_S_FETCH_REQ;
        end
      end

      CPU_S_MEM_REQ: begin
        if (bus_gnt_i) state_d = CPU_S_MEM_WAIT;
      end

      CPU_S_MEM_WAIT: begin
        if (bus_rvalid_i) begin
          if (decoded_i.mem_read) begin
            state_d = CPU_S_WRITEBACK;
          end else begin
            state_d = CPU_S_FETCH_REQ;
          end
        end
      end

      CPU_S_WRITEBACK: begin
        state_d = CPU_S_FETCH_REQ;
      end

      CPU_S_TRAP: begin
        state_d = CPU_S_TRAP;
      end

      default: begin
        state_d = CPU_S_TRAP;
      end
    endcase
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_q <= CPU_S_RESET;
    end else begin
      state_q <= state_d;
    end
  end

  assign fetch_req_o  = (state_q == CPU_S_FETCH_REQ);
  assign instr_we_o   = (state_q == CPU_S_FETCH_WAIT) && bus_rvalid_i;
  assign execute_we_o = (state_q == CPU_S_EXECUTE);
  assign mem_req_o    = (state_q == CPU_S_MEM_REQ);
  assign load_we_o    = (state_q == CPU_S_MEM_WAIT) && bus_rvalid_i && decoded_i.mem_read;
  assign reg_we_o     = (state_q == CPU_S_WRITEBACK) && decoded_i.reg_write && !trap_o;

  // PC changes after branches/jumps, after stores complete, after normal writeback,
  // and after NOP-like instructions such as FENCE.
  assign pc_we_o = ((state_q == CPU_S_EXECUTE) && !mem_fault_i && (decoded_i.branch || decoded_i.jump)) ||
                   ((state_q == CPU_S_MEM_WAIT) && bus_rvalid_i && decoded_i.mem_write) ||
                   ((state_q == CPU_S_WRITEBACK) && !trap_o && !decoded_i.branch && !decoded_i.jump) ||
                   ((state_q == CPU_S_EXECUTE) && !mem_fault_i &&
                    !decoded_i.mem_read && !decoded_i.mem_write &&
                    !decoded_i.branch && !decoded_i.jump && !decoded_i.reg_write);

endmodule
