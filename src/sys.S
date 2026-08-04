.syntax unified
.thumb



/*!<
 * globals
 * */
// objects
.global tick

// functions
.global sys_tick_handler
.global delay_ms



/*!<
 * variables
 * */
.section .data.tick
.type tick, %object				/* uint64_t tick; */
tick: .quad 0x0000000000000000
.size tick, .-tick



/*!<
 * functions
 * */
.section .text.sys_tick_handler
.type sys_tick_handler, %function	/* void sys_tick_handler(void); */
sys_tick_handler:
	ldr ip, =tick				// load tick ptr 
	ldmia ip, {r0-r1}			// load multiple src  (2 * 32-bit)
	adds r0, r0, #1				// inc low word
	adc  r1, r1, #0				// add carry to high word
	stm ip, {r0-r1}				// store multiple dst (2 * 32-bit)
	bx lr						// return
.size sys_tick_handler, .-sys_tick_handler


.section .text.delay_ms
.type delay_ms, %function			/* void delay_ms(uint64_t); */
delay_ms:
	push {r4, r5}
	ldr ip, =tick
	ldmia ip, {r2, r3}
.delay_loop:	
	ldmia ip, {r4, r5}
	subs r4, r4, r2
	sbc  r5, r5, r3
	cmp  r4, r0
	sbcs r5, r5, r1
	bcc .delay_loop
	pop {r4, r5}
	bx lr
.size delay_ms, .-delay_ms

