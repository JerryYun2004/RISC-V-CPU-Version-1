.section .text.start
.global _start
_start:
  addi x1, x0, 42
  addi x2, x0, 0x100
  sw   x1, 0(x2)
  lw   x3, 0(x2)
  bne  x1, x3, fail
  jal  x0, pass

pass:
  lui  x5, 0x30000
  lui  x6, 0xcafe0
  addi x6, x6, 2
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
halt:
  jal  x0, halt

fail:
  lui  x5, 0x30000
  lui  x6, 0xdead0
  addi x6, x6, 2
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
  jal  x0, halt
