OUTPUT_ARCH( "riscv" )
ENTRY( _start )

SECTIONS
{
  . = 0x80000000;
  
  .text : {
    *(.text.entry)
    *(.text .text.*)
  }
  
  .rodata : {
    *(.rodata .rodata.*)
  }
  
  .data : {
    *(.data .data.*)
  }
  
  .bss : {
    *(.bss .bss.*)
  }

  .eh_frame : {
    *(.eh_frame)
  }
}