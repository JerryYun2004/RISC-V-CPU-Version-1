/* test_soc_branch_jump.S
 * Verify branch/JAL/JALR control flow when running through the SoC wrapper.
 * PASS code: 0xcafe000d
 */
.option norvc
.section .text
.global _start
_start:
    jal  x1, after_jal       /* x1 should receive PC+4 */
    jal  x0, fail            /* must be skipped */

after_jal:
    addi x3, x0, 4
    bne  x1, x3, fail

    addi x4, x0, 0
loop:
    addi x4, x4, 1
    addi x7, x0, 3
    bne  x4, x7, loop

    lui  x5, %hi(pass)
    addi x5, x5, %lo(pass)
    jalr x0, 0(x5)

pass:
    lui  x5, 0x30000
    lui  x6, 0xcafe0
    addi x6, x6, 0x00d
    sw   x6, 4(x5)           /* RESULT_CODE */
    addi x6, x0, 1
    sw   x6, 0(x5)           /* DONE */

fail:
    lui  x5, 0x30000
    lui  x6, 0xdead0
    addi x6, x6, 0x00d
    sw   x6, 4(x5)
    addi x6, x0, 1
    sw   x6, 0(x5)
