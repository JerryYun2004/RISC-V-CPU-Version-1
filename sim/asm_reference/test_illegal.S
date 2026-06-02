/* Expected behavior: CPU enters trap on unsupported/illegal instruction. */
.option norvc
.section .text
.global _start
_start:
    .word 0x00000000   /* illegal instruction in RV32I */
