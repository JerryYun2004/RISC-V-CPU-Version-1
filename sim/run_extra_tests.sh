#!/usr/bin/env bash
set -euo pipefail

# Run from the sim/ directory of your repository after copying the .hex files into sim/programs/.
TESTS=(
  test_rtype
  test_itype
  test_load_store
  test_x0
  test_jalr_align
)

make build
for t in "${TESTS[@]}"; do
  echo ""
  echo "===== Running $t ====="
  ./obj_dir/Vtb_cpu_top +hex=programs/${t}.hex +max-cycles=${MAX_CYCLES:-200000}
done

echo ""
echo "All extra ISA tests passed."
