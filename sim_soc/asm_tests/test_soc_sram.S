/* test_soc_sram.S
 * Verify store/load through SoC SRAM address region.
 * PASS code: 0xcafe000b
 */
.option norvc
.section .text
.global _start
_start:
    addi x1, x0, 42          /* test value */
    addi x2, x0, 0x100       /* SRAM data address, away from code */

    sw   x1, 0(x2)
    lw   x3, 0(x2)
    bne  x1, x3, fail

pass:
    lui  x5, 0x30000         /* MMIO base */
    lui  x6, 0xcafe0
    addi x6, x6, 0x00b
    sw   x6, 4(x5)           /* RESULT_CODE */
    addi x6, x0, 1
    sw   x6, 0(x5)           /* DONE */

fail:
    lui  x5, 0x30000
    lui  x6, 0xdead0
    addi x6, x6, 0x00b
    sw   x6, 4(x5)
    addi x6, x0, 1
    sw   x6, 0(x5)
