#ifndef SDL_RECTWRAPPER_HPP
#define SDL_RECTWRAPPER_HPP

#include <cstdint>
#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>

struct SDL_RectWrapper : public SDL_Rect
{
	SDL_RectWrapper( const Point& NWCorner = Point( 0, 0 ), const uint16_t& w = 0, const uint16_t& h = 0 ) : SDL_Rect()
	{
		SDL_Rect::x = NWCorner.x;
		SDL_Rect::y = NWCorner.y;
		SDL_Rect::w = w;
		SDL_Rect::h = h;
	}

	SDL_RectWrapper( const int16_t& x, const int16_t& y, const uint16_t& w, const uint16_t& h ) : SDL_Rect()
	{
		SDL_Rect::x = x;
		SDL_Rect::y = y;
		SDL_Rect::w = w;
		SDL_Rect::h = h;
	}

	SDL_RectWrapper( const uint16_t& w, const uint16_t& h) : SDL_Rect()
	{
		SDL_Rect::w = w;
		SDL_Rect::h = h;
	}
};

#endif
