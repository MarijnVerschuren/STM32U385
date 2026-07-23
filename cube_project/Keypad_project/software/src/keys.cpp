#include <keys.hpp>




keys_t::keys_t(const uint8_t* map, uint8_t width, uint8_t height): w(width), h(height), map(map) {
	this->active = (uint8_t*)malloc(this->w * this->h);
}

keys_t::~keys_t(void) {
	free(this->active);
}


uint8_t keys_t::width(void) const	{ return this->w; }
uint8_t keys_t::height(void) const	{ return this->h; }
uint8_t* keys_t::begin(void)		{ return this->active; }
uint8_t* keys_t::end(void)			{ return &this->active[this->active_cnt]; }






key_scan_t::key_scan_t(
	_O uint32_t* ODR, uint16_t omsk,
	_I uint32_t* IDR, uint16_t imsk,
	const uint8_t* map
) : keys_t(map, __builtin_popcount(omsk), __builtin_popcount(imsk)), omsk(omsk), imsk(imsk) {
	this->ODR = ODR;
	this->IDR = IDR;
	(*this->ODR) &=	~this->omsk;	// clear output
	this->wo =	__builtin_ctz(omsk);
	this->ho =	__builtin_ctz(imsk);
	this->counts = (uint8_t*)malloc(this->w * this->h);
}

key_scan_t::~key_scan_t(void) {
	free(this->counts);
}

/* piecewise key_scan update function
 * - returns:	true if cycle complete false otherwise
 * - uses:		this->state = [0, 2*this->w]
 */
uint8_t key_scan_t::update(void) {
	if (this->state & 0x1) {	// odd state => column active
		uint16_t active = ((*this->IDR) & this->imsk) >> this->ho;
		(*this->ODR) &=	~this->omsk;	// clear col output
		this->process_bitmask(this->state >> 1U, active);
		this->state = ((this->state + 1U) % (this->w << 1U));
		return !this->state;
	}
	(*this->ODR) |= 0x1 << (this->wo + (this->state >> 1U));
	this->state++;
	return 0;
}

void key_scan_t::update_active(void) {
	this->active_cnt = 0;
	for (uint8_t i = 0; i < this->w; i++) {
		for (uint8_t j = 0; j < this->h; j++) {
			if (this->counts[i * this->h + j] < DEBOUNCE_CNT) { continue; }
			this->active[this->active_cnt] = this->map[j * this->w + i];
			this->active_cnt++;
		}
	}
}

uint8_t* key_scan_t::begin(void) {
	this->update_active();
	return this->active;
}




void key_scan_t::process_bitmask(uint8_t column, uint16_t mask) {
	uint8_t* col = &counts[column * this->h];
	for (uint8_t i = 0; i < this->h; i++, mask >>= 1U) {
		if (!(mask & 0b1U)) {
			col[i] = 0;
			continue;
		}
		col[i]++;
	}
}



// TODO
key_send_t::key_send_t(const uint8_t* map, uint8_t width, uint8_t height) : keys_t(map, width, height) {

}
