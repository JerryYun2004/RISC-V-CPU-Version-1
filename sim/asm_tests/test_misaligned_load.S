.section .text.start
.global _start
_start:
  addi x1, x0, 0x101
  lw   x2, 0(x1)
  jal  x0, fail

fail:
  lui  x5, 0x30000
  lui  x6, 0xdead0
  addi x6, x6, 10
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
halt:
  jal  x0, halt
