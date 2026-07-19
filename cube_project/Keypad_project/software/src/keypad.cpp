#include <keys.hpp>
#include "PAL.h"



const uint8_t key_map[4][3] = {
	{'0', '1', '2'},
	{'3', '4', '5'},
	{'6', '7', '8'},
	{'9', 'A', 'B'}
};


key_scan_t keypad_scan(
	&GPIOD->ODR, 0x7U << 5U,	// D5 - D7
	&GPIOE->IDR, 0xFU << 1U,	// E1 - E4
	(uint8_t*)key_map
);




// called by TIMx update IRQ
extern "C" void key_scan_tick_handler(void) {
	if (!keypad_scan.update()) { return; }
	for (uint8_t key : keypad_scan) {
		printf("pressed: %c\n", key);
	}
}


// TODO: make tim interrupt
// TODO: link tim interrupt to key_scan_tick
// TODO: edit _write to send via usart3
uint8_t buf[8] = {0, 0, 0x04, 0, 0, 0, 0, 0};

extern "C" void keypad_main(void) {
	//USART3_NS
	uint64_t prev = get_tick();
	for(;;) {
		if (get_tick() - prev > 10000) {
			prev = get_tick();
			GPIO_toggle(GPIOA, 15);
			HID_send_msg(buf);
		}
		HID_run_tasks();
	}
}
