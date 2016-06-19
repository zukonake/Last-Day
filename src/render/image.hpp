#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <iostream>
#include <SDL/SDL.h>
//
#include <render/interface.hpp>

class Image
{
	SDL_Surface* value;
public:
	friend std::istream& operator >> ( std::istream& in, Image& obj );
	friend std::ostream& operator << ( std::ostream& out, const Image& obj );
	void render( SDL_Rect* sourcePosition, Interface* targetInterface, SDL_Rect* targetPosition );
	Image();
};

#endif
