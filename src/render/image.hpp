#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <memory>
#include <iostream>
#include <SDL/SDL.h>

class Image
{
protected:
	SDL_Surface* surface;
public:
	virtual void render( SDL_Rect& sourcePosition, SDL_Surface& targetSurface, SDL_Rect& targetPosition );

	Image( std::istream& in );
	Image();
	virtual ~Image();

	operator SDL_Surface ();
};

#endif
