# Simulation Tools

## `build_hex.sh`

Builds a RISC-V assembly file into the `.hex` format used by `simple_mem.sv`.

Example:

```bash
cd sim
tools/build_hex.sh asm_reference/test_rtype.S programs/test_rtype.hex
```

By default, it uses `riscv64-unknown-elf-gcc`, `objcopy`, and `objdump`.
Override the tool prefix with:

```bash
CROSS_COMPILE=riscv32-unknown-elf- tools/build_hex.sh asm_reference/test_rtype.S
```

## `disasm_hex.sh`

Disassembles a `.hex` program for debugging:

```bash
cd sim
tools/disasm_hex.sh programs/test_addi.hex
```

## `bin_to_hex.py`

Converts a raw little-endian RV32 binary into one 32-bit hex word per line.
