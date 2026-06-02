OUTPUT_ARCH(riscv)
ENTRY(_start)

MEMORY
{
  RAM (rwx) : ORIGIN = 0x00000000, LENGTH = 64K
}

SECTIONS
{
  . = ORIGIN(RAM);
  .text : ALIGN(4)
  {
    KEEP(*(.text.start))
    *(.text*)
    *(.rodata*)
  } > RAM

  .data : ALIGN(4)
  {
    *(.sdata*)
    *(.data*)
  } > RAM

  .bss : ALIGN(4)
  {
    *(.sbss*)
    *(.bss*)
    *(COMMON)
  } > RAM

  /DISCARD/ :
  {
    *(.comment*)
    *(.riscv.attributes*)
    *(.note*)
  }
}
