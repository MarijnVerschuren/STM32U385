SECTIONS {
	_heap_size = 0x200;
	_stack_size = 0x400;

	_stack_end = ORIGIN(SRAM) + LENGTH(SRAM);
	_stack_start = _stack_end - _stack_size;

	. = ORIGIN(SRAM);

	.data ALIGN(4) : {
		_data_start = .;
		*(.data)
		*(.data*)
		. = ALIGN(4);
		_data_end = .;
	} > SRAM AT > FLASH

	_data_load = LOADADDR(.data);

	.bss ALIGN(4) (NOLOAD) : {
		_bss_start = .;
		*(.bss)
		*(.bss*)
		. = ALIGN(4);
		_bss_end = .;
	} > SRAM

	._user_heap_stack ALIGN(8) : {
		_heap_start = .;
		. = . + _heap_size;
		. = . + _stack_size;
		. = ALIGN(8);
	} > SRAM
}