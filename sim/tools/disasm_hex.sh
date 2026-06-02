#!/usr/bin/env bash
set -euo pipefail

# Disassemble a one-word-per-line .hex program.
#
# Usage from sim/:
#   tools/disasm_hex.sh programs/test_addi.hex
#
# Requires riscv64-unknown-elf-objdump or set CROSS_COMPILE.

if [[ $# -ne 1 ]]; then
  echo "Usage: $0 program.hex" >&2
  exit 2
fi

CROSS_COMPILE="${CROSS_COMPILE:-riscv64-unknown-elf-}"
OBJDUMP="${CROSS_COMPILE}objdump"
HEX="$1"
TMP_BIN="$(mktemp /tmp/rv32_hex_XXXXXX.bin)"
trap 'rm -f "$TMP_BIN"' EXIT

python3 - "$HEX" "$TMP_BIN" <<'PY'
import sys
from pathlib import Path
hex_path = Path(sys.argv[1])
bin_path = Path(sys.argv[2])
out = bytearray()
for raw in hex_path.read_text().splitlines():
    line = raw.strip()
    if not line or line.startswith('#'):
        continue
    word = int(line, 16)
    out += word.to_bytes(4, 'little')
bin_path.write_bytes(out)
PY

"$OBJDUMP" -D -b binary -m riscv:rv32 "$TMP_BIN"
