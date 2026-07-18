#include <keys.hpp>
#include "PAL.h"



const uint8_t key_map[4][3] = {
	{'0', '1', '2'},
	{'3', '4', '5'},
	{'6', '7', '8'},
	{'9', 'A', 'B'}
};


key_scan_t keypad_scan(&GPIOD->ODR, 0x7U << 5U, &GPIOE->IDR, 0xFU << 1U, key_map);




// called by TIMx update IRQ
extern "C" void key_scan_tick_handler(void) {
	if (!keys.update()) { return; }
	for (uint8_t i = 0; i < keys.width(); i++) {
		for (uint8_t j = 0; j < keys.height(); j++) {
			if (!((keys[i] >> j) & 0b1U)) { continue; }

			// TODO: debounce
			// TODO: decode
			// TODO: alter HID msg
		}
	}
}


extern "C" void keypad_main(void) {

	for(;;) {
		GPIO_toggle(GPIOA, 15);
		delay_ms(500);
	}
}
