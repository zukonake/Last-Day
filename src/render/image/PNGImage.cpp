#include "PNGImage.hpp"
#include <exception>
#include <SDL2/SDL_image.h>

void PNGImage::load( SDL_Renderer* renderer )
{
	if( renderer == nullptr )
	{
		throw std::invalid_argument( "PNGImage::load, null pointer given in argument 1." );
		return;
	}
	SDL_Surface* loadingSurface = IMG_Load( path.c_str() );
	if( loadingSurface == nullptr )
	{
		throw std::runtime_error( "PNGImage::load, couldn't load loadingSurface: " + path + " ." );
		return;
	}
	texture = SDL_CreateTextureFromSurface( renderer, loadingSurface );
	SDL_FreeSurface( loadingSurface );
	return;
}
