#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <SDL/SDL.h>

class Image
{
protected:
	SDL_Surface* surface;
public:
	virtual void render( SDL_Rect* sourcePosition, SDL_Surface* targetSurface, SDL_Rect* targetPosition );

	Image();

	friend std::istream& operator >> ( std::istream& in, Image& obj );
	friend std::ostream& operator << ( std::ostream& out, const Image& obj );
	
	operator SDL_Surface ();
};

#endif
