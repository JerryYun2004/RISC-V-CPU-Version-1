# Verilator simple SoC verification Makefile
#
# Expected project layout:
#   project_root/
#     cpu_rtl/cpu/          CPU RTL files
#     soc/                  SoC wrapper RTL files
#     sim_soc/              this directory

VERILATOR ?= verilator
CPU_DIR   ?= ../cpu_rtl/cpu
SOC_DIR   ?= ../soc
TOP       ?= soc_top
PROGRAM   ?= $(PROGRAM)
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

SOC_SRCS = \
  $(SOC_DIR)/soc_pkg.sv \
  $(SOC_DIR)/soc_sram.sv \
  $(SOC_DIR)/mmio_debug.sv \
  $(SOC_DIR)/soc_top.sv

CPP_SRCS = tb_soc.cpp

VERILATOR_FLAGS = -sv -Wall -Wno-fatal \
  -Wno-DECLFILENAME \
  -Wno-UNUSEDSIGNAL \
  -Wno-UNUSEDPARAM \
  -Wno-CASEINCOMPLETE \
  -I$(CPU_DIR) \
  -I$(SOC_DIR) \
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

SOC_TESTS = $(PROGRAM)

.PHONY: build run test_soc clean list build_hex

build:
	$(VERILATOR) $(VERILATOR_FLAGS) $(CPU_SRCS) $(SOC_SRCS) $(CPP_SRCS)

run: build
	./obj_dir/V$(TOP) $(RUN_ARGS)

test_soc: build
	@set -e; \
	for p in $(SOC_TESTS); do \
	  echo ""; \
	  echo "===== Running SoC test $$p ====="; \
	  ./obj_dir/V$(TOP) +hex=programs/$$p.hex +max-cycles=$(MAX_CYCLES); \
	done

build_hex:
	./tools/build_soc_hex.sh asm_tests/$(PROGRAM).S programs/$(PROGRAM).hex

list:
	@ls programs/*.hex | sed 's#programs/##; s#.hex##'

clean:
	rm -rf obj_dir tb_soc.vcd build
