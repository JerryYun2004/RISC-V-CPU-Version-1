.section .text.start
.global _start
_start:
  .word 0xffffffff
  jal x0, _start
