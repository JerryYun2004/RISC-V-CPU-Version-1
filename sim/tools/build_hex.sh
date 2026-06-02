#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 || $# -gt 2 ]]; then
  echo "Usage: $0 asm_tests/test_name.S [programs/test_name.hex]" >&2
  exit 2
fi

ASM="$1"
OUT_HEX="${2:-}"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SIM_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$SIM_DIR/build/asm"
mkdir -p "$BUILD_DIR" "$SIM_DIR/programs"

if [[ -z "$OUT_HEX" ]]; then
  base="$(basename "$ASM" .S)"
  OUT_HEX="$SIM_DIR/programs/${base}.hex"
fi

if [[ -n "${RISCV_PREFIX:-}" ]]; then
  GCC="${RISCV_PREFIX}-gcc"
  OBJCOPY="${RISCV_PREFIX}-objcopy"
  OBJDUMP="${RISCV_PREFIX}-objdump"
elif command -v riscv64-unknown-elf-gcc >/dev/null 2>&1; then
  GCC="riscv64-unknown-elf-gcc"
  OBJCOPY="riscv64-unknown-elf-objcopy"
  OBJDUMP="riscv64-unknown-elf-objdump"
elif command -v riscv32-unknown-elf-gcc >/dev/null 2>&1; then
  GCC="riscv32-unknown-elf-gcc"
  OBJCOPY="riscv32-unknown-elf-objcopy"
  OBJDUMP="riscv32-unknown-elf-objdump"
else
  echo "ERROR: Could not find riscv64-unknown-elf-gcc or riscv32-unknown-elf-gcc." >&2
  echo "Install a RISC-V bare-metal toolchain, or set RISCV_PREFIX manually." >&2
  exit 1
fi

base="$(basename "$ASM" .S)"
ELF="$BUILD_DIR/${base}.elf"
BIN="$BUILD_DIR/${base}.bin"
DUMP="$BUILD_DIR/${base}.dump"

"$GCC" \
  -march=rv32i -mabi=ilp32 \
  -nostdlib -nostartfiles -ffreestanding \
  -Wl,--no-relax -Wl,--build-id=none \
  -T "$SCRIPT_DIR/link.ld" \
  -o "$ELF" "$ASM"

"$OBJCOPY" -O binary "$ELF" "$BIN"
"$OBJDUMP" -d "$ELF" > "$DUMP"
"$SCRIPT_DIR/bin_to_hex.py" "$BIN" "$OUT_HEX"

echo "[build_hex] ASM  $ASM"
echo "[build_hex] ELF  $ELF"
echo "[build_hex] DUMP $DUMP"
echo "[build_hex] HEX  $OUT_HEX"
