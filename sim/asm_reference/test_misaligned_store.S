/* Expected behavior: CPU enters trap on misaligned SW. */
.option norvc
.section .text
.global _start
_start:
    addi x1, x0, 1     /* x1 = 1, not word-aligned */
    lui  x2, 0x12345
    addi x2, x2, 0x678
    sw   x2, 0(x1)     /* misaligned word store -> trap */
