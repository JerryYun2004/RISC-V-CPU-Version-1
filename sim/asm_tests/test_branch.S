.section .text.start
.global _start
_start:
  addi x1, x0, 5
  addi x2, x0, 5
  beq  x1, x2, equal_ok
  jal  x0, fail

equal_ok:
  addi x3, x0, 10
  addi x4, x0, 0
loop:
  addi x4, x4, 1
  blt  x4, x3, loop
  bne  x4, x3, fail
  jal  x0, pass

pass:
  lui  x5, 0x30000
  lui  x6, 0xcafe0
  addi x6, x6, 3
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
halt:
  jal  x0, halt

fail:
  lui  x5, 0x30000
  lui  x6, 0xdead0
  addi x6, x6, 3
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
  jal  x0, halt
