#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <memory>
#include <iostream>
#include <SDL2/SDL.h>

class Image
{
protected:
	SDL_Texture* texture;
public:
	static SDL_Renderer* renderer;
	virtual void render( SDL_Renderer* targetRenderer, SDL_Rect& sourcePosition, SDL_Rect& targetPosition );

	Image( std::istream& in );
	Image();
	virtual ~Image();
};

#endif
