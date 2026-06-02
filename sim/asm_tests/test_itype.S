.section .text.start
.global _start
_start:
  addi x1, x0, 10
  addi x3, x1, -3
  addi x7, x0, 7
  bne  x3, x7, fail

  andi x3, x1, 3
  addi x7, x0, 2
  bne  x3, x7, fail

  ori  x3, x1, 1
  addi x7, x0, 11
  bne  x3, x7, fail

  xori x3, x1, 15
  addi x7, x0, 5
  bne  x3, x7, fail

  slli x3, x1, 2
  addi x7, x0, 40
  bne  x3, x7, fail

  srli x3, x1, 1
  addi x7, x0, 5
  bne  x3, x7, fail

  addi x2, x0, -8
  srai x3, x2, 3
  addi x7, x0, -1
  bne  x3, x7, fail

  slti x3, x1, 11
  addi x7, x0, 1
  bne  x3, x7, fail

  sltiu x3, x1, 11
  addi x7, x0, 1
  bne  x3, x7, fail

  jal  x0, pass

pass:
  lui  x5, 0x30000
  lui  x6, 0xcafe0
  addi x6, x6, 6
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
halt:
  jal  x0, halt

fail:
  lui  x5, 0x30000
  lui  x6, 0xdead0
  addi x6, x6, 6
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
  jal  x0, halt
