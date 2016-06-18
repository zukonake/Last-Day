#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL/SDL.h>
//
#include <render/image.hpp>
#include <render/interface.hpp>

class Sprite
{
	Image* sourceImage;
	SDL_Rect positionOnImage;
public:
	Sprite( Image* sourceImage, SDL_Rect positionOnImage );
	void render( Interface* targetInterface, SDL_Rect* targetPosition );
};

#endif
