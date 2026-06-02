# Simulation Tools

## `build_hex.sh`

Build one assembly test into a `.hex` file:

```bash
./tools/build_hex.sh asm_tests/test_addi.S
```

## `build_all_hex.sh`

Build all tests from `asm_tests/*.S` into `programs/*.hex`:

```bash
./tools/build_all_hex.sh
```

## `disasm_hex.sh`

Disassemble a generated hex file:

```bash
./tools/disasm_hex.sh programs/test_addi.hex
```

## `bin_to_hex.py`

Converts a raw little-endian RISC-V binary into one 32-bit hex word per line for `$readmemh`.
