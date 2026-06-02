.section .text.start
.global _start
_start:
  addi x0, x0, 123
  addi x1, x0, 0
  bne  x1, x0, fail

  addi x10, x0, 0x100
  addi x2, x0, 77
  sw   x2, 0(x10)
  lw   x0, 0(x10)
  addi x1, x0, 0
  bne  x1, x0, fail

  add  x0, x2, x2
  addi x1, x0, 0
  bne  x1, x0, fail

  jal  x0, pass

pass:
  lui  x5, 0x30000
  lui  x6, 0xcafe0
  addi x6, x6, 8
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
halt:
  jal  x0, halt

fail:
  lui  x5, 0x30000
  lui  x6, 0xdead0
  addi x6, x6, 8
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
  jal  x0, halt
