#!/usr/bin/env bash
set -euo pipefail

echo "[run_soc_tests] Building SoC .hex files from asm_tests/*.S"

mkdir -p programs

if command -v riscv64-unknown-elf-gcc >/dev/null 2>&1 || \
   command -v riscv32-unknown-elf-gcc >/dev/null 2>&1 || \
   [[ -n "${RISCV_PREFIX:-}" ]]; then

  for asm in asm_tests/*.S; do
    name="$(basename "$asm" .S)"
    echo "[run_soc_tests] Build ${name}"
    ./tools/build_soc_hex.sh "$asm" "programs/${name}.hex"
  done

else
  echo "[run_soc_tests] RISC-V GCC not found; using existing programs/*.hex files."
fi

run_test() {
  local name="$1"
  echo
  echo "===== Running SoC test ${name} ====="
  make test_soc PROGRAM="$name"
}

run_test test_soc_smoke
run_test test_soc_sram
run_test test_soc_mmio
run_test test_soc_branch_jump

echo
echo "[run_soc_tests] PASS: all SoC tests passed."
