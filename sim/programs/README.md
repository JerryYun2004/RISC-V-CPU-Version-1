# Verilator Program Hex Tests

Each `.hex` file contains one 32-bit little-endian RISC-V instruction word per line, formatted for `$readmemh()` in `simple_mem.sv`.

## Baseline tests

| Program | Purpose |
|---|---|
| `test_addi.hex` | Basic immediate arithmetic and register writeback |
| `test_lw_sw.hex` | Word store/load and SRAM access |
| `test_branch.hex` | Conditional branches and PC redirect |
| `test_jump.hex` | JAL/JALR, PC redirect, and link register writeback |

## Extra RV32I directed tests

| Program | Purpose |
|---|---|
| `test_rtype.hex` | R-type ALU operations: add, sub, logic, shifts, comparisons |
| `test_itype.hex` | I-type ALU operations: addi, logic immediates, shifts, comparisons |
| `test_load_store.hex` | Byte, halfword, word loads/stores and sign/zero extension |
| `test_x0.hex` | Confirms writes to x0 are ignored |
| `test_jalr_align.hex` | Confirms JALR clears bit 0 and writes PC+4 to rd |

## Expected-trap tests

These tests should be run with `+expect-trap`.

| Program | Purpose |
|---|---|
| `test_illegal.hex` | Confirms an illegal/unsupported instruction enters trap cleanly |
| `test_misaligned_load.hex` | Confirms misaligned word load enters trap cleanly |
| `test_misaligned_store.hex` | Confirms misaligned word store enters trap cleanly |

Note: the current CPU bus has no `bus_err_i` input, so truly unmapped addresses cannot currently trap at the CPU level. The current memory fault tests therefore use misalignment, which your CPU already detects internally.
