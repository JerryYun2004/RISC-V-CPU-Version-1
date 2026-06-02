# RISC-V CPU Version 1

This repository contains a simple RV32I-style RISC-V CPU written in SystemVerilog, together with CPU-only and simple SoC-level Verilator verification flows.

The project currently includes:

- A CPU RTL implementation under `cpu_rtl/cpu/`
- CPU-only Verilator simulation under `sim/`
- Assembly-based CPU regression tests under `sim/asm_tests/`
- A simple SoC wrapper under `soc/`
- SoC-level Verilator simulation under `sim_soc/`
- Assembly-based SoC regression tests under `sim_soc/asm_tests/`

## Repository Structure

```text
cpu_rtl/cpu/
├── alu.sv
├── branch_unit.sv
├── control_fsm.sv
├── cpu_pkg.sv
├── cpu_top.sv
├── decoder.sv
├── imm_gen.sv
├── lsu.sv
└── regfile.sv

sim/
├── Makefile
├── tb_cpu.cpp
├── simple_mem.sv
├── run_all_tests.sh
├── asm_tests/
├── programs/
└── tools/

soc/
├── soc_pkg.sv
├── soc_top.sv
├── soc_sram.sv
└── mmio_debug.sv

sim_soc/
├── Makefile
├── tb_soc.cpp
├── run_soc_tests.sh
├── asm_tests/
├── programs/
└── tools/

