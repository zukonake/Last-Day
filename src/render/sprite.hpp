#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <iostream>
#include <SDL2/SDL.h>
//
#include <render/image.hpp>

class Sprite : protected Image
{
protected:
	SDL_Rect positionOnImage;
public:
	virtual void render( SDL_Renderer* targetRenderer, SDL_Rect& targetPosition );
protected:
	Sprite( std::istream& in );
	Sprite();
	virtual ~Sprite();
};

#endif
