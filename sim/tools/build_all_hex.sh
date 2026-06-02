#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SIM_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

for asm in "$SIM_DIR"/asm_tests/test_*.S; do
  "$SCRIPT_DIR/build_hex.sh" "$asm"
done
