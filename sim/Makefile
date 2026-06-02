# Verilator CPU-only verification Makefile
#
# Expected project layout:
#   project_root/
#     cpu/                 CPU RTL files
#     sim/                 this directory
#
# If your CPU RTL is somewhere else, override CPU_DIR:
#   make CPU_DIR=../cpu_rtl/cpu run PROGRAM=test_addi

VERILATOR ?= verilator
CPU_DIR   ?= ../cpu_rtl/cpu
TOP       ?= tb_cpu_top
PROGRAM   ?= test_addi
MAX_CYCLES ?= 200000
WAVE      ?= 0

CPU_SRCS = \
  $(CPU_DIR)/cpu_pkg.sv \
  $(CPU_DIR)/alu.sv \
  $(CPU_DIR)/regfile.sv \
  $(CPU_DIR)/imm_gen.sv \
  $(CPU_DIR)/branch_unit.sv \
  $(CPU_DIR)/lsu.sv \
  $(CPU_DIR)/decoder.sv \
  $(CPU_DIR)/control_fsm.sv \
  $(CPU_DIR)/cpu_top.sv

SIM_SRCS = simple_mem.sv
CPP_SRCS = tb_cpu.cpp

VERILATOR_FLAGS = -sv -Wall -Wno-fatal \
  -Wno-DECLFILENAME \
  -Wno-UNUSEDSIGNAL \
  -Wno-UNUSEDPARAM \
  -Wno-CASEINCOMPLETE \
  -I$(CPU_DIR) \
  --cc --exe --build \
  --top-module $(TOP)

ifeq ($(WAVE),1)
VERILATOR_FLAGS += --trace
RUN_ARGS += +wave
endif

RUN_ARGS += +hex=programs/$(PROGRAM).hex +max-cycles=$(MAX_CYCLES)

.PHONY: build run test_all clean list

build:
	$(VERILATOR) $(VERILATOR_FLAGS) $(CPU_SRCS) $(SIM_SRCS) $(CPP_SRCS)

run: build
	./obj_dir/V$(TOP) $(RUN_ARGS)

list:
	@ls programs/*.hex | sed 's#programs/##; s#.hex##'

test_all: build
	@set -e; \
	for p in test_addi test_lw_sw test_branch test_jump; do \
	  echo ""; \
	  echo "===== Running $$p ====="; \
	  ./obj_dir/V$(TOP) +hex=programs/$$p.hex +max-cycles=$(MAX_CYCLES); \
	done

clean:
	rm -rf obj_dir tb_cpu.vcd logs
