SECTIONS
{
    . = 0x10000;
    .text : { *(.text) }
    .data : { *(.data) }
    .bss  : { *(.bss) }
    .rodata  : { *(.rodata) }
    /DISCARD/ : { *(.eh_frame) *(.comment) *(.note) *(.note.*) *(.note.GNU-stack) }
}
