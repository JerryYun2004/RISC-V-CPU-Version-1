#!/usr/bin/env bash
set -euo pipefail

# Expanded SoC regression runner.
# Run from sim_soc/.

if [[ ! -f Makefile ]]; then
  echo "[run_soc_tests] ERROR: run this script from sim_soc/." >&2
  exit 1
fi

if command -v riscv64-unknown-elf-gcc >/dev/null 2>&1 || command -v riscv32-unknown-elf-gcc >/dev/null 2>&1 || [[ -n "${RISCV_PREFIX:-}" ]]; then
  if [[ -x ./tools/build_all_soc_hex.sh ]]; then
    echo "[run_soc_tests] Building SoC .hex files from asm_tests/*.S"
    ./tools/build_all_soc_hex.sh
  else
    echo "[run_soc_tests] build_all_soc_hex.sh not found; using existing programs/*.hex files."
  fi
else
  echo "[run_soc_tests] RISC-V GCC not found; using existing programs/*.hex files."
fi

TESTS=(
  test_soc_smoke
  test_soc_sram
  test_soc_mmio
  test_soc_branch_jump
)

make build

for t in "${TESTS[@]}"; do
  echo
  echo "===== Running SoC test ${t} ====="
  make run PROGRAM="$t"
done

echo
echo "[run_soc_tests] PASS: all SoC tests passed."
