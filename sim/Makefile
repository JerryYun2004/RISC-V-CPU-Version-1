# Verilator CPU-only verification Makefile
#
# Expected project layout:
#   project_root/
#     cpu_rtl/cpu/          CPU RTL files
#     sim/                  this directory

VERILATOR ?= verilator
CPU_DIR   ?= ../cpu_rtl/cpu
TOP       ?= tb_cpu_top
PROGRAM   ?= test_addi
MAX_CYCLES ?= 200000
WAVE      ?= 0
EXPECT_TRAP ?= 0

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

ifeq ($(EXPECT_TRAP),1)
RUN_ARGS += +expect-trap
endif

RUN_ARGS += +hex=programs/$(PROGRAM).hex +max-cycles=$(MAX_CYCLES)

BASELINE_TESTS = test_addi test_lw_sw test_branch test_jump
EXTRA_TESTS    = test_rtype test_itype test_load_store test_x0 test_jalr_align
TRAP_TESTS     = test_illegal test_misaligned_load test_misaligned_store

.PHONY: build run test_all test_extra test_trap test_regression clean list

build:
	$(VERILATOR) $(VERILATOR_FLAGS) $(CPU_SRCS) $(SIM_SRCS) $(CPP_SRCS)

run: build
	./obj_dir/V$(TOP) $(RUN_ARGS)

list:
	@ls programs/*.hex | sed 's#programs/##; s#.hex##'

test_all: build
	@set -e; \
	for p in $(BASELINE_TESTS); do \
	  echo ""; \
	  echo "===== Running $$p ====="; \
	  ./obj_dir/V$(TOP) +hex=programs/$$p.hex +max-cycles=$(MAX_CYCLES); \
	done

test_extra: build
	@set -e; \
	for p in $(EXTRA_TESTS); do \
	  echo ""; \
	  echo "===== Running $$p ====="; \
	  ./obj_dir/V$(TOP) +hex=programs/$$p.hex +max-cycles=$(MAX_CYCLES); \
	done

test_trap: build
	@set -e; \
	for p in $(TRAP_TESTS); do \
	  echo ""; \
	  echo "===== Running $$p / expected trap ====="; \
	  ./obj_dir/V$(TOP) +hex=programs/$$p.hex +max-cycles=$(MAX_CYCLES) +expect-trap; \
	done

test_regression: test_all test_extra test_trap

clean:
	rm -rf obj_dir tb_cpu.vcd logs build_hex
