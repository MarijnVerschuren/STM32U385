
/*!<
 * includes
 * */
#include <keys.hpp>
#include "PAL.h"



/*!<
 * constants
 * */
const uint8_t key_map[4][3] = {
	{'1', '2', '3'},
	{'q', 'w', 'e'},
	{'a', 's', 'd'},
	{'z', 'x', 'c'}
};



/*!<
 * variables
 * */
key_scan_t keypad_scan(
	&GPIOD->ODR, 0x7U << 5U,	// D5 - D7
	&GPIOE->IDR, 0xFU << 1U,	// E1 - E4
	(uint8_t*)key_map
);

uint8_t key_count;
uint8_t report[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t prev_report[8];

volatile uint8_t USB_HID_active = 0;
volatile uint8_t USB_HID_update = 0;




/*!<
 * call-backs and IRQs
 * */
extern "C" void USB_HID_enumerated_callback(void) { USB_HID_active = 1; }
extern "C" void USB_HID_disconnect_callback(void) { USB_HID_active = 0; }

extern "C" void rotary_button_handler(uint8_t dir) {	// 0: down, 1: up
	GPIO_toggle(GPIOA, 15);
}

extern "C" void key_scan_tick_handler(void) {
	if (!keypad_scan.update()) { return; }

	((uint64_t*)report)[0] = 0;
	key_count = 2;							// TODO: modifiers!

	for (uint8_t key : keypad_scan) {
		report[key_count++] = key;
		if (key_count == 8) { break; }		// TODO: multi-report?
	}

	if (((uint64_t*)report)[0] == ((uint64_t*)prev_report)[0]) { return; }
	((uint64_t*)prev_report)[0] = ((uint64_t*)report)[0];
	USB_HID_update = 1;
}




// TODO: make tim interrupt
// TODO: link tim interrupt to key_scan_tick
// TODO: edit _write to send via usart3

extern "C" void keypad_main(void) {
	uint64_t prev = get_tick();
	for(;;) {
		if (USB_HID_update) {
			USB_HID_update = 0;
//			for (uint8_t i = 2; i < 8; i++) {
//				printf("%c", report[i]);
//				if (i == 7) { printf("\n"); }
//				else		{ printf(", "); }
//			}
		}
//		if (get_tick() - prev > 1000) {
//			prev = get_tick();
//			//GPIO_toggle(GPIOA, 15);
//		}
	}
}

// call     dcd -> ux_slave_dcd_function(dcd, UX_DCD_TASKS_RUN, UX_NULL);
// where ux_slave_dcd_function == NULL


