#!/usr/bin/env bash
set -euo pipefail

# Build one assembly test into a .hex file for simple_mem.sv.
#
# Usage from sim/:
#   tools/build_hex.sh asm_reference/test_rtype.S
#   tools/build_hex.sh asm_reference/test_rtype.S programs/test_rtype.hex
#
# Requires a RISC-V GNU toolchain in PATH. Default prefix:
#   riscv64-unknown-elf-
# Override with:
#   CROSS_COMPILE=riscv32-unknown-elf- tools/build_hex.sh ...

if [[ $# -lt 1 || $# -gt 2 ]]; then
  echo "Usage: $0 input.S [output.hex]" >&2
  exit 2
fi

CROSS_COMPILE="${CROSS_COMPILE:-riscv64-unknown-elf-}"
CC="${CROSS_COMPILE}gcc"
OBJCOPY="${CROSS_COMPILE}objcopy"
OBJDUMP="${CROSS_COMPILE}objdump"

ASM="$1"
BASE="$(basename "${ASM%.*}")"
OUT_HEX="${2:-programs/${BASE}.hex}"
BUILD_DIR="build_hex/${BASE}"

mkdir -p "$BUILD_DIR" "$(dirname "$OUT_HEX")"

ELF="$BUILD_DIR/${BASE}.elf"
BIN="$BUILD_DIR/${BASE}.bin"
DIS="$BUILD_DIR/${BASE}.dump"

"$CC" \
  -march=rv32i \
  -mabi=ilp32 \
  -nostdlib \
  -nostartfiles \
  -ffreestanding \
  -Wl,-T,tools/link.ld \
  -Wl,--no-relax \
  -o "$ELF" \
  "$ASM"

"$OBJCOPY" -O binary "$ELF" "$BIN"
python3 tools/bin_to_hex.py "$BIN" "$OUT_HEX"
"$OBJDUMP" -d "$ELF" > "$DIS"

echo "Built: $OUT_HEX"
echo "ELF:   $ELF"
echo "Dump:  $DIS"
