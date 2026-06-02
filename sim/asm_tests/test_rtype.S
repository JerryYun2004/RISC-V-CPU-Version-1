.section .text.start
.global _start
_start:
  addi x1, x0, 10
  addi x2, x0, 3
  add  x3, x1, x2
  addi x7, x0, 13
  bne  x3, x7, fail

  sub  x3, x1, x2
  addi x7, x0, 7
  bne  x3, x7, fail

  and  x3, x1, x2
  addi x7, x0, 2
  bne  x3, x7, fail

  or   x3, x1, x2
  addi x7, x0, 11
  bne  x3, x7, fail

  xor  x3, x1, x2
  addi x7, x0, 9
  bne  x3, x7, fail

  sll  x3, x2, x2
  addi x7, x0, 24
  bne  x3, x7, fail

  addi x8, x0, 32
  srl  x3, x8, x2
  addi x7, x0, 4
  bne  x3, x7, fail

  addi x8, x0, -8
  sra  x3, x8, x2
  addi x7, x0, -1
  bne  x3, x7, fail

  slt  x3, x2, x1
  addi x7, x0, 1
  bne  x3, x7, fail

  sltu x3, x2, x1
  addi x7, x0, 1
  bne  x3, x7, fail

  jal  x0, pass

pass:
  lui  x5, 0x30000
  lui  x6, 0xcafe0
  addi x6, x6, 5
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
halt:
  jal  x0, halt

fail:
  lui  x5, 0x30000
  lui  x6, 0xdead0
  addi x6, x6, 5
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
  jal  x0, halt
