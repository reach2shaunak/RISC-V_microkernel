ENTRY(boot)

SECTIONS {
	. = 0x80200000;	

	.text :{
		KEEP(*(.text.boot));
		*(.text .text.*);	
	}

	.rodata : ALIGN(4) {
		*(.rodata ..rodata.*);	
	}

	.data : ALIGN(4) {
		*(.data .data.*);
	}
	#bss section
	.bss : ALIGN(4) {
		__bss = .; /* similar to "extern char symbol_name" in c*/
		*(.bss .bss.* .sbss .sbss.*);
		__bss_end = .;
	}

	/*Get 64MB of space for memory allocation:heap*/
	. = ALIGN(4096);/*page aligned*/
	__heap_start = .;
	. += 64 * 1024 * 1024 ; /*128 MB*/
	__heap_end = .;
	
	. = ALIGN(4);
	. += 128 *1024; /*128kb*/
	__stack_top = .;

}
