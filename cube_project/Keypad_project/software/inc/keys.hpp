#pragma once 

#include "PAL.h"



#define DEBOUNCE_CNT 10



class keys_t {
public:
	keys_t(const uint8_t* map, uint8_t width, uint8_t height);
	~keys_t(void);
	
	uint8_t		width(void)		const;	// this->w
	uint8_t		height(void)	const;	// this->h
	
	// iter array of active keys
	uint8_t*	begin(void);
    uint8_t*	end(void);

private:
	const uint8_t	w:	4;
	const uint8_t	h:	4;
	const uint8_t*	map;
	
	uint8_t*		active;
	uint8_t			active_cnt;
	
	friend class key_scan_t;
};





class key_scan_t : public keys_t {
public:
	key_scan_t(
		_O uint32_t* ODR, uint16_t omsk,
		_I uint32_t* IDR, uint16_t imsk,
		const uint8_t* map
	);
	~key_scan_t(void);
	
	uint8_t		update(void);	// call each tick (progress column activation)
	
	void		update_active(void);
	uint8_t*	begin(void);
	 
private:
	void process_bitmask(uint8_t column, uint16_t mask);

private:
	uint8_t	state = 0;

	uint8_t	wo:	4;	// width offset
	uint8_t	ho:	4;	// height offset
	
	const uint16_t omsk;
	const uint16_t imsk;
	
	_O uint32_t*	ODR;
	_I uint32_t*	IDR;
	
	uint8_t*		counts;
};



// TODO: send keys
class key_send_t : public keys_t {
public:
	key_send_t(const uint8_t* map, uint8_t width, uint8_t height);
	
};


