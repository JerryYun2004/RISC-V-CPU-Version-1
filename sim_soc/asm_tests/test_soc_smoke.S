/*
 * test_soc_smoke.S
 *
 * Minimal SoC-level smoke test.
 * Checks that the CPU can execute from the SoC SRAM and write to SoC MMIO.
 *
 * PASS result: 0xCAFE000A
 * FAIL result: 0xDEAD000A
 */

.section .text
.global _start
_start:
    addi x1, x0, 7
    addi x2, x0, 35
    add  x3, x1, x2
    addi x4, x0, 42
    bne  x3, x4, fail

pass:
    lui  x5, 0x30000       /* x5 = 0x3000_0000 */
    lui  x6, 0xcafe0       /* x6 = 0xCAFE_0000 */
    addi x6, x6, 0x00a     /* x6 = 0xCAFE_000A */
    sw   x6, 4(x5)         /* RESULT_CODE */
    addi x6, x0, 1
    sw   x6, 0(x5)         /* DONE */

fail:
    lui  x5, 0x30000
    lui  x6, 0xdead0
    addi x6, x6, 0x00a
    sw   x6, 4(x5)
    addi x6, x0, 1
    sw   x6, 0(x5)
