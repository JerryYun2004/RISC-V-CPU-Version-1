# SoC Test Programs

| Program | Purpose | Expected Result Code |
|---|---|---|
| `test_soc_smoke.hex` | Basic SoC smoke test | `0xcafe000a` |
| `test_soc_sram.hex` | Store/load through SoC SRAM | `0xcafe000b` |
| `test_soc_mmio.hex` | MMIO RESULT_CODE and DONE writes | `0xcafe000c` |
| `test_soc_branch_jump.hex` | Branch/JAL/JALR through SoC wrapper | `0xcafe000d` |
