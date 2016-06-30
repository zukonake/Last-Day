#include "PNGImage.hpp"

void PNGImage::load( SDL_Renderer* renderer )
{
	if( renderer == nullptr )
	{
		throw std::invalid_argument( "ERROR: PNGImage::load, null pointer given in argument 1." );
		return;
	}
	SDL_Surface* loadingSurface = IMG_Load( path.c_str() );
	if( loadingSurface == nullptr )
	{
		throw std::runtime_error( "ERROR: PNGImage::load, couldn't load loadingSurface: " + path + " ." );
		return;
	}
	texture = SDL_CreateTextureFromSurface( renderer, loadingSurface );
	SDL_FreeSurface( loadingSurface );
	return;
}
