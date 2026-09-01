.syntax unified
.thumb

// include memory map defines with the C preprocessor
#include "memory_map.h"	// define include

// functions
.global init_io_buffer
.global in_available
.global out_available


/*!<
 * functions
 * */
// io_buffer_t* init_io_buffer(uint32_t size, uint8_t flags);
.section .text.init_io_buffer
.type init_io_buffer, %function
init_io_buffer:
	push {r4-r6, lr}			// push non-volatile registers
	mov r4, r0					// r4: size
	mov r5, r1					// r5: flags
	bl calloc					// allocate buffer
	mov r6, r0					// r6: ptr
	mov r0, #16					// sizeof(io_buffer_t)
	bl calloc					// allocate buffer
	str r6, [r0]				// buffer->ptr
	lsl r1, r5, #31				// shift to ien flag
	lsl r2, r5, #30				// shift to oen flag
	lsl r3, r5, #29				// shift to fifo flag
	and r1, r1, #0x80000000		// ien flag
	and r2, r2, #0x80000000		// oen flag
	and r3, r3, #0x80000000		// fifo flag
	orr r3, r3, r4				// add size
	add r4, r0, #4				// add offset
	stm r4, {r1-r3}				// store data
	pop {r4-r6, lr}				// restore non-volatile registers
	bx lr						// return
.size init_io_buffer, .-init_io_buffer


// uint32_t in_available(io_buffer_t* buffer);
.section .text.in_available
.type in_available, %function
in_available:
	add r0, r0, #4		// skip buffer pointer
	ldmia r0, {r1, r2}	// load I and O offsets
	bfc r1, #31, #1		// remove mode bit
	bfc r2, #31, #1		// remove mode bit
	sub r0, r1, r2		// calculate I - O
	bx lr
.size in_available, .-in_available


// uint32_t out_available(io_buffer_t* buffer);
.section .text.out_available
.type out_available, %function
out_available:
	add r0, r0, #4		// skip buffer pointer
	ldmia r0, {r1, r2}	// load I and O offsets
	bfc r1, #31, #1		// remove mode bit
	bfc r2, #31, #1		// remove mode bit
	sub r0, r2, r1		// calculate O - I
	bx lr
.size out_available, .-out_available


