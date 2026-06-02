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

## Extra RV32I Directed Tests

| Test | Purpose | Result |
|---|---|---|
| `test_rtype` | R-type ALU operations: add, sub, logic, shifts, comparisons | PASS |
| `test_itype` | I-type ALU operations: addi, logic immediates, shifts, comparisons | PASS |
| `test_load_store` | Byte, halfword, word loads/stores and sign/zero extension | PASS |
| `test_x0` | Confirms writes to x0 are ignored | PASS |
| `test_jalr_align` | Confirms JALR clears bit 0 and writes PC+4 to rd | PASS |

## Current Status

The CPU passes the current CPU-only Verilator regression suite. The verified scope includes basic RV32I arithmetic, immediate operations, load/store behavior, branch redirects, jump redirects, x0 behavior, and JALR alignment behavior.
