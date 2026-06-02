#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
  echo "Usage: $0 programs/test_name.hex" >&2
  exit 2
fi

HEX="$1"
TMP_BIN="$(mktemp /tmp/rv32_hex_XXXXXX.bin)"
trap 'rm -f "$TMP_BIN"' EXIT

python3 - "$HEX" "$TMP_BIN" <<'PY'
import sys
from pathlib import Path
hex_path = Path(sys.argv[1])
bin_path = Path(sys.argv[2])
out = bytearray()
for line in hex_path.read_text().splitlines():
    line = line.strip()
    if not line or line.startswith('#'):
        continue
    word = int(line, 16)
    out += word.to_bytes(4, 'little')
bin_path.write_bytes(out)
PY

if [[ -n "${RISCV_PREFIX:-}" ]]; then
  OBJDUMP="${RISCV_PREFIX}-objdump"
elif command -v riscv64-unknown-elf-objdump >/dev/null 2>&1; then
  OBJDUMP="riscv64-unknown-elf-objdump"
elif command -v riscv32-unknown-elf-objdump >/dev/null 2>&1; then
  OBJDUMP="riscv32-unknown-elf-objdump"
else
  echo "ERROR: Could not find RISC-V objdump." >&2
  exit 1
fi

"$OBJDUMP" -D -b binary -m riscv:rv32 "$TMP_BIN"
