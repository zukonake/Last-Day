#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Image
{
protected:
	SDL_Texture* texture;
	std::string imagePath;
public:
	virtual void render( SDL_Renderer* targetRenderer, SDL_Rect& sourcePosition, SDL_Rect& targetPosition );
	void initialize( SDL_Renderer* targetRenderer );

	Image( std::istream& in );
	Image();
	virtual ~Image();
};

#endif
