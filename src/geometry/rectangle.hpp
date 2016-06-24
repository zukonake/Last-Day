
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cstdint>
#include <iostream>
#include <SDL/SDL.h>

struct Rectangle
{
	uint16_t width;
	uint16_t height;

	Rectangle( const uint16_t& width, const uint16_t& height ) : width( width ), height( height ) { }
	Rectangle( std::istream& in );
	Rectangle() { }

	operator SDL_Rect ();
};

#endif
