#pragma once 

#include "PAL.h"







class key_map_t {
public:
	key_map_t(const uint8_t* map, uint8_t width, uint8_t height);
	~key_map_t(void);


private:
	const uint8_t	width:	4;
	const uint8_t	height:	4;
	const uint8_t*	map;
	uint8_t*		counts;
	
	
	friend class key_scan_t;
}





class key_scan_t {
public:
	key_scan_t(
		_O uint32_t* ODR, uint16_t omsk,
		_I uint32_t* IDR, uint16_t imsk,
		const uint8_t* map
	);
	~key_scan_t(void);
	
	uint8_t		update(void);	// call each tick (progress column activation)
	
	uint8_t		width(void)				const;
	uint8_t		height(void)			const;
	uint16_t	operator[](uint8_t idx)	const;
	uint16_t*	begin(void)				const;
    uint16_t*	end(void)				const;

private:
	uint8_t		state = 0;

	uint8_t	wo:	4;	// width offset
	uint8_t	ho:	4;	// height offset
	
	const uint16_t omsk;
	const uint16_t imsk;
	
	_O uint32_t*	ODR;
	_I uint32_t*	IDR;
	
	uint16_t*		active;	// TODO: use map.counts instead!!
	key_map_t		map;
};

