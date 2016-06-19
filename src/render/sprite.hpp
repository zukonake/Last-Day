#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <iostream>
#include <SDL/SDL.h>
//
#include <render/image.hpp>
#include <render/interface.hpp>

class Sprite
{
	Image* sourceImage;
	SDL_Rect positionOnImage;
public:
	friend std::istream& operator >> ( std::istream& in, Sprite& obj );
	friend std::ostream& operator << ( std::ostream& out, const Sprite& obj );
	void render( Interface* targetInterface, SDL_Rect* targetPosition );
	Sprite( Image* sourceImage, SDL_Rect positionOnImage );
	Sprite();
};

#endif
