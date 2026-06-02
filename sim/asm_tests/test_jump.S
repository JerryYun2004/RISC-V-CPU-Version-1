.section .text.start
.global _start
_start:
  jal  x1, after_jal
  jal  x0, fail

after_jal:
  addi x3, x0, 4
  bne  x1, x3, fail
  auipc x5, 0
  addi  x5, x5, 16
  jalr  x0, 0(x5)
  jal   x0, fail

target:
  jal  x0, pass

pass:
  lui  x5, 0x30000
  lui  x6, 0xcafe0
  addi x6, x6, 4
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
halt:
  jal  x0, halt

fail:
  lui  x5, 0x30000
  lui  x6, 0xdead0
  addi x6, x6, 4
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
  jal  x0, halt
