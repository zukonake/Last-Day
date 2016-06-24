#include "rectangle.hpp"
#include <geometry/SDL_RectWrapper.hpp>

Rectangle::Rectangle( std::istream& in )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> width;
	in >> height;
	std::cout << "INFO: Initializing rectangle: " << width << ", " << height << ".\n";
}

Rectangle::operator SDL_Rect ()
{
	return static_cast< SDL_Rect >( SDL_RectWrapper( this->width, this->height ) );
}
