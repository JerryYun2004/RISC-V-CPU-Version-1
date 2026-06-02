#!/usr/bin/env bash
set -euo pipefail

# Full CPU-only regression runner.
# Assumes it is executed from the sim/ directory.

run_normal() {
  local name="$1"
  echo
  echo "===== Running ${name} ====="
  make run PROGRAM="$name"
}

run_trap() {
  local name="$1"
  echo
  echo "===== Running ${name} / expected trap ====="
  make run PROGRAM="$name" EXPECT_TRAP=1
}

# Build hex files from assembly first when the toolchain is available.
if command -v riscv64-unknown-elf-gcc >/dev/null 2>&1 || command -v riscv32-unknown-elf-gcc >/dev/null 2>&1 || [[ -n "${RISCV_PREFIX:-}" ]]; then
  echo "[run_all_tests] Building .hex files from sim/asm_tests/*.S"
  ./tools/build_all_hex.sh
else
  echo "[run_all_tests] RISC-V GCC not found; using existing programs/*.hex files."
  echo "[run_all_tests] To rebuild from assembly, install riscv64-unknown-elf-gcc or set RISCV_PREFIX."
fi

run_normal test_addi
run_normal test_lw_sw
run_normal test_branch
run_normal test_jump
run_normal test_rtype
run_normal test_itype
run_normal test_load_store
run_normal test_x0
run_normal test_jalr_align

run_trap test_illegal
run_trap test_misaligned_load
run_trap test_misaligned_store 

echo
echo "[run_all_tests] PASS: all CPU regression tests passed."
