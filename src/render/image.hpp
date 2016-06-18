#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <SDL/SDL.h>
//
#include <render/interface.hpp>

class Image
{
	SDL_Surface* value;
public:
	Image( std::string sourceFile );
	void render( SDL_Rect* sourcePosition, Interface* targetInterface, SDL_Rect* targetPosition );
};

#endif
