SECTIONS {
	. = ORIGIN(FLASH);

	.vector ALIGN(4) : {
		_IVT_start = .;
		KEEP(*(.vector))
		. = ALIGN(4);
		_ITV_end = .;
	} > FLASH

	.text ALIGN(4) : {
		_text_start = .;
		*(.text)
		*(.text*)
		. = ALIGN(4);
		_text_end = .;
	} > FLASH

	.rodata ALIGN(4) : {
		*(.rodata)
		*(.rodata*)
		. = ALIGN(4);
	} > FLASH
}