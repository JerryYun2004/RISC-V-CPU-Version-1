#!/usr/bin/env bash
set -euo pipefail

# Build all sim_soc/asm_tests/*.S files into sim_soc/programs/*.hex.
# Run from sim_soc/.

if [[ ! -d asm_tests ]]; then
  echo "[build_all_soc_hex] ERROR: run this script from sim_soc/." >&2
  exit 1
fi

if [[ ! -x tools/build_soc_hex.sh ]]; then
  echo "[build_all_soc_hex] ERROR: tools/build_soc_hex.sh not found or not executable." >&2
  exit 1
fi

for asm in asm_tests/*.S; do
  [[ -e "$asm" ]] || continue
  ./tools/build_soc_hex.sh "$asm"
done
