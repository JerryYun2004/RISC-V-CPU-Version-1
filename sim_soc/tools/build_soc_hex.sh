#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 2 ]]; then
  echo "Usage: $0 <input.S> <output.hex>" >&2
  exit 2
fi

ASM_IN="$1"
HEX_OUT="$2"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SIM_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
BUILD_DIR="$SIM_DIR/build/asm"
mkdir -p "$BUILD_DIR"

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
  echo "[build_soc_hex] ERROR: RISC-V GCC not found." >&2
  echo "Install riscv64-unknown-elf-gcc or set RISCV_PREFIX." >&2
  exit 1
fi

NAME="$(basename "$ASM_IN" .S)"
ELF="$BUILD_DIR/$NAME.elf"
BIN="$BUILD_DIR/$NAME.bin"
DUMP="$BUILD_DIR/$NAME.dump"

mkdir -p "$(dirname "$HEX_OUT")"

echo "[build_soc_hex] ASM  $ASM_IN"
"$GCC" -march=rv32i -mabi=ilp32 -nostdlib -nostartfiles -ffreestanding \
  -Wl,-T,"$SCRIPT_DIR/link.ld" \
  -Wl,--no-relax \
  -o "$ELF" "$ASM_IN"

"$OBJDUMP" -d "$ELF" > "$DUMP"
"$OBJCOPY" -O binary "$ELF" "$BIN"
"$SCRIPT_DIR/bin_to_hex.py" "$BIN" "$HEX_OUT"

echo "[build_soc_hex] ELF  $ELF"
echo "[build_soc_hex] DUMP $DUMP"
echo "[build_soc_hex] HEX  $HEX_OUT"
