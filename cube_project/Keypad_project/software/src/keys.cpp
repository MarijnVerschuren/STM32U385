#include <keys.hpp>




key_map_t::key_map_t(const uint8_t* map, uint8_t width, uint8_t height): map(map), width(width), height(height) {
	this->counts = malloc(width * height);
}

key_map_t::~key_map_t(void) {
	free(this->counts);
}





key_scan_t::key_scan_t(
	_O uint32_t* ODR, uint16_t omsk,
	_I uint32_t* IDR, uint16_t imsk,
	const uint8_t* map
) : omsk(omsk), imsk(imsk), map(map, __builtin_popcount(omsk), __builtin_popcount(imsk)) {
	this->ODR = ODR;
	this->IDR = IDR;
	(*this->ODR) &=	~this->omsk;	// clear output
	this->wo =	__builtin_ctz(omsk);
	this->ho =	__builtin_ctz(imsk);

	this->active = malloc(this->map.width);
}

key_scan_t::~key_scan_t(void) {
	free(this->active);
}


/* piecewise key_scan update function
 * - returns:	row number when de-bounce is reached otherwise -1
 * - uses:		this->state = [0, 2*this->w]
 */
uint8_t key_scan_t::update(void) {
	if (this->state & 0x1) {	// odd state => column active
		uint16_t active = ((*this->IDR) & this->imsk) >> this->ho;
		(*this->ODR) &=	~this->omsk;	// clear col output
		this->state = ((this->state + 1U) % (this->map.width << 1U));

		if (!this->state) { return 1; }
		// TODO: use counts!!

		return -1;
	}
	(*this->ODR) |= 0x1 << (this->wo + (this->state >> 1U));
	this->state++;
	return -1;
}

uint8_t key_scan_t::width(void) const				{ return this->map.width; }
uint8_t key_scan_t::height(void) const				{ return this->map.height; }
uint16_t key_scan_t::operator[](uint8_t idx) const	{
	if (idx < this->map.width) {
		return this->active[idx];
	} return -1;
}
uint16_t* key_scan_t::begin(void) const				{ return this->active; }
uint16_t* key_scan_t::end(void) const				{ return &this->active[this->map.width - 1]; }



