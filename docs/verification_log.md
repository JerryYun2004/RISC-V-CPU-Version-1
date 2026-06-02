# Verification Log

## Baseline CPU-only Verilator Tests

Simulation top:

- `sim/simple_mem.sv: tb_cpu_top`

Testbench:

- `sim/tb_cpu.cpp`

Memory model:

- `sim/simple_mem.sv`

## Current Results

| Test | Purpose | Result |
|---|---|---|
| `test_addi` | Basic arithmetic, immediate decode, register writeback | PASS |
| `test_lw_sw` | Store/load path and simple SRAM access | PASS |
| `test_branch` | Conditional branches and PC redirect | PASS |
| `test_jump` | JAL/JALR jump path and link register writeback | PASS |

## Important Fixes

- Changed the control FSM to use the current decoded instruction during decode/execute decision.
- Fixed jump instructions so `JAL/JALR` write `PC + 4` to `rd`.
- Fixed PC update timing so branch/jump targets use the current calculated next PC instead of a stale registered value.
