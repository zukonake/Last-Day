#include "image.hpp"
#include <string>
#include <SDL2/SDL_image.h>

SDL_Renderer* Image::renderer;

void Image::render( SDL_Renderer* targetRenderer, SDL_Rect& sourcePosition, SDL_Rect& targetPosition )
{
	SDL_RenderCopy( renderer, texture, &sourcePosition, &targetPosition );
}

Image::Image( std::istream& in )
{
	const unsigned int maximumVariableLength = 256;
	std::string imagePath;
	in.ignore( maximumVariableLength, ' ' );
	in >> imagePath;
	std::cout << "INFO: Initializing image: "<< imagePath << " .\n";
	texture = SDL_CreateTextureFromSurface( renderer, IMG_Load( std::string( imagePath ).c_str() ) );
	if( texture == NULL )
	{
		//TODO throw exception
		std::cout << "ERROR: Couldn't load image: "<< imagePath << " .\n";
	}
}

Image::Image() : texture( NULL )
{

}

Image::~Image()
{
	if( texture != NULL )
	{
		std::cout << "INFO: Image destructor called\n";
		SDL_DestroyTexture( texture );
	}
}
