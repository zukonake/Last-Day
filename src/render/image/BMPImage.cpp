#include "BMPImage.hpp"

void BMPImage::load( SDL_Renderer* renderer )
{
	if( renderer == NULL )
	{
		throw std::invalid_argument( "ERROR: BMPImage::load, null pointer given in argument 1." );
		return;
	}
	SDL_Surface* loadingSurface = SDL_LoadBMP( path.c_str() );
	if( loadingSurface == NULL )
	{
		throw std::runtime_error( "ERROR: BMPImage::load, couldn't load loadingSurface." );
		return;
	}
	texture = SDL_CreateTextureFromSurface( renderer, loadingSurface );
	SDL_FreeSurface( loadingSurface );
	return;
}
