#include "image.hpp"

std::istream& operator >> ( std::istream& in, Image& obj )
{
	const unsigned int maximumVariableLength = 256;
	std::string imagePath;
	in >> imagePath;
	//TODO load image
	return in;
}

std::ostream& operator << ( std::ostream& out, const Image& obj )
{
	return out;
}

void Image::render( SDL_Rect* sourcePosition, SDL_Surface* targetSurface, SDL_Rect* targetPosition )
{
	SDL_BlitSurface( surface, sourcePosition, targetSurface , targetPosition );
}

Image::Image()
{

}

Image::~Image()
{
	
}

Image::operator SDL_Surface ()
{
	return *surface;
}
