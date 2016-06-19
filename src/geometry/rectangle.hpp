#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cstdint>
#include <iostream>

struct Rectangle
{
	uint16_t width;
	uint16_t height;
	friend std::istream& operator >> ( std::istream& in, Rectangle& obj );
	friend std::ostream& operator << ( std::ostream& out, const Rectangle& obj );
	Rectangle( uint16_t width, uint16_t height ) : width( width ), height( height ) { }
	Rectangle();
};

#endif
