#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cstdint>

struct Rectangle
{
	uint16_t width;
	uint16_t height;
	Rectangle( uint16_t width, uint16_t height ) : width( width ), height( height ) { }
};

#endif
