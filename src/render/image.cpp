#include "image.hpp"
#include <string>
#include <SDL/SDL_image.h>

void Image::render( SDL_Rect& sourcePosition, SDL_Surface& targetSurface, SDL_Rect& targetPosition )
{
	SDL_BlitSurface( surface, &sourcePosition, &targetSurface , &targetPosition );
}

Image::Image( std::istream& in )
{
	const unsigned int maximumVariableLength = 256;
	std::string imagePath;
	in.ignore( maximumVariableLength, ' ' );
	in >> imagePath;
	std::cout << "INFO: Initializing image: "<< imagePath << " .\n";
	surface = IMG_Load( std::string( imagePath ).c_str() );
	if( surface == NULL )
	{
		//TODO throw exception
		std::cout << "ERROR: Couldn't load image: "<< imagePath << " .\n";
	}
}

Image::Image() : surface( NULL )
{

}

Image::~Image()
{
	if( surface != NULL && surface->flags != SDL_SWSURFACE )
	{
		std::cout << "INFO: Image destructor called\n";
		SDL_FreeSurface( surface );
	}
}

Image::operator SDL_Surface ()
{
	return *surface;
}
