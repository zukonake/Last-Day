#include "BMPImage.hpp"

void BMPImage::load( SDL_Renderer* renderer )
{
	if( renderer == nullptr )
	{
		throw std::invalid_argument( "BMPImage::load, null pointer given in argument 1." );
		return;
	}
	SDL_Surface* loadingSurface = SDL_LoadBMP( path.c_str() );
	if( loadingSurface == nullptr )
	{
		throw std::runtime_error( "BMPImage::load, couldn't load loadingSurface." );
		return;
	}
	texture = SDL_CreateTextureFromSurface( renderer, loadingSurface );
	SDL_FreeSurface( loadingSurface );
	return;
}
