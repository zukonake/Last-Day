#include "rectangle.hpp"

Rectangle::Rectangle( std::istream& in )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> width;
	in >> height;
	std::cout << "INFO: Initializing rectangle: " << width << ", " << height << ".\n";
}

Rectangle::operator SDL_RectWrapper ()
{
	return SDL_RectWrapper( this->width, this->height );
}
