# Verilator Program Hex Files

This directory stores `.hex` files loaded by `simple_mem.sv` using `$readmemh`.
Each line is one 32-bit little-endian RISC-V instruction/data word printed as an 8-digit hex value.

The preferred source of truth is now `../asm_tests/*.S`.
Rebuild all `.hex` files with:

```bash
cd sim
./tools/build_all_hex.sh
```

Run the full regression with:

```bash
cd sim
./run_all_tests.sh
```

## Tests

| Hex file | Purpose | Expected result |
|---|---|---|
| `test_addi.hex` | Basic ADDI/arithmetic/writeback | `0xcafe0001` |
| `test_lw_sw.hex` | Basic word load/store | `0xcafe0002` |
| `test_branch.hex` | Conditional branch and loop behavior | `0xcafe0003` |
| `test_jump.hex` | JAL/JALR jump/link behavior | `0xcafe0004` |
| `test_rtype.hex` | R-type ALU instructions | `0xcafe0005` |
| `test_itype.hex` | I-type ALU instructions | `0xcafe0006` |
| `test_load_store.hex` | Byte/halfword/word load-store behavior | `0xcafe0007` |
| `test_x0.hex` | Hardwired x0 behavior | `0xcafe0008` |
| `test_jalr_align.hex` | JALR target bit-0 clearing | `0xcafe0009` |
| `test_illegal.hex` | Illegal instruction handling | expected trap |
| `test_misaligned_load.hex` | Misaligned load handling | expected trap |
| `test_misaligned_store.hex` | Misaligned store handling | expected trap |
