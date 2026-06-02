.section .text.start
.global _start
_start:
  // Build an intentionally odd JALR target. JALR must clear bit 0.
  auipc x5, 0
  addi  x5, x5, 17
  jalr  x1, 0(x5)
  jal   x0, fail

target:
  // x1 should contain the link address from JALR, so it must be nonzero.
  beq   x1, x0, fail
  jal   x0, pass

pass:
  lui  x5, 0x30000
  lui  x6, 0xcafe0
  addi x6, x6, 9
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
halt:
  jal  x0, halt

fail:
  lui  x5, 0x30000
  lui  x6, 0xdead0
  addi x6, x6, 9
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
  jal  x0, halt
