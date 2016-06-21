
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cstdint>
#include <iostream>
#include <SDL/SDL.h>
//
#include <render/sdl_rectWrapper.hpp>

struct Rectangle
{
	uint16_t width;
	uint16_t height;

	Rectangle( const uint16_t& width, const uint16_t& height ) : width( width ), height( height ) { }
	Rectangle();

	friend std::istream& operator >> ( std::istream& in, Rectangle& obj );
	friend std::ostream& operator << ( std::ostream& out, const Rectangle& obj );

	operator SDL_Rect ();
};

#endif
