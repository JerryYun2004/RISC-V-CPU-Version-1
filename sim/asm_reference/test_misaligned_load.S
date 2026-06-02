/* Expected behavior: CPU enters trap on misaligned LW. */
.option norvc
.section .text
.global _start
_start:
    addi x1, x0, 1     /* x1 = 1, not word-aligned */
    lw   x2, 0(x1)     /* misaligned word load -> trap */
