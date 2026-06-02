/* test_soc_mmio.S
 * Verify SoC MMIO RESULT_CODE and DONE registers.
 * PASS code: 0xcafe000c
 */
.option norvc
.section .text
.global _start
_start:
    lui  x5, 0x30000         /* MMIO base */

    /* Write an intermediate value first, then overwrite with final PASS. */
    lui  x6, 0x11111
    addi x6, x6, 0x111
    sw   x6, 4(x5)

    lui  x6, 0xcafe0
    addi x6, x6, 0x00c
    sw   x6, 4(x5)           /* RESULT_CODE */

    addi x6, x0, 1
    sw   x6, 0(x5)           /* DONE */
