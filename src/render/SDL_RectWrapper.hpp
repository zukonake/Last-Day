#ifndef SDL_RECTWRAPPER_HPP
#define SDL_RECTWRAPPER_HPP

#include <SDL/SDL.h>
#include <cstdint>

class SDL_RectWrapper : private SDL_Rect
{
public:
	SDL_RectWrapper( Point2D NWCorner, uint16_t w, uint16_t h ) : x(NWCorner.x), y(NWCorner.y), w(w), h(h) { }
	SDL_RectWrapper( int16_t x, int16_t y, uint16_t w, uint16_t h ) : x(x), y(y), w(w), h(h) { }
	SDL_RectWrapper( uint16_t w, uint16_t h ) : w(w), h(h) { }
};

#endif
