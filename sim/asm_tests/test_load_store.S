.section .text.start
.global _start
_start:
  addi x10, x0, 0x100

  lui  x1, 0xa1b2c
  addi x1, x1, 0x3d4
  sw   x1, 0(x10)

  lw   x2, 0(x10)
  bne  x1, x2, fail

  lbu  x2, 0(x10)
  addi x7, x0, 0x0d4
  bne  x2, x7, fail

  lb   x2, 0(x10)
  addi x7, x0, -44
  bne  x2, x7, fail

  lhu  x2, 0(x10)
  lui  x7, 0x0000c
  addi x7, x7, 0x3d4
  bne  x2, x7, fail

  lh   x2, 0(x10)
  lui  x7, 0xffffc
  addi x7, x7, 0x3d4
  bne  x2, x7, fail

  addi x3, x0, 0x55
  sb   x3, 4(x10)
  lbu  x4, 4(x10)
  bne  x3, x4, fail

  lui  x3, 0x0000a
  addi x3, x3, 0x5a5
  sh   x3, 8(x10)
  lhu  x4, 8(x10)
  bne  x3, x4, fail

  jal  x0, pass

pass:
  lui  x5, 0x30000
  lui  x6, 0xcafe0
  addi x6, x6, 7
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
halt:
  jal  x0, halt

fail:
  lui  x5, 0x30000
  lui  x6, 0xdead0
  addi x6, x6, 7
  sw   x6, 4(x5)
  addi x6, x0, 1
  sw   x6, 0(x5)
  jal  x0, halt
