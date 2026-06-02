#!/usr/bin/env bash
set -euo pipefail

# Runs the complete CPU-only Verilator regression suite.
# Run from sim/:
#   ./run_all_tests.sh

NORMAL_TESTS=(
  test_addi
  test_lw_sw
  test_branch
  test_jump
  test_rtype
  test_itype
  test_load_store
  test_x0
  test_jalr_align
)

TRAP_TESTS=(
  test_illegal
  test_misaligned_load
  test_misaligned_store
)

make build

for t in "${NORMAL_TESTS[@]}"; do
  echo ""
  echo "===== Running ${t} ====="
  ./obj_dir/Vtb_cpu_top +hex="programs/${t}.hex" +max-cycles=200000
done

for t in "${TRAP_TESTS[@]}"; do
  echo ""
  echo "===== Running ${t} / expected trap ====="
  ./obj_dir/Vtb_cpu_top +hex="programs/${t}.hex" +max-cycles=200000 +expect-trap
done

echo ""
echo "===== ALL CPU TESTS PASSED ====="
