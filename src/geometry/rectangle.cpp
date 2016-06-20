#include "rectangle.hpp"

std::istream& operator >> ( std::istream& in, Rectangle& obj )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> obj.width;
	in >> obj.height;
	return in;
}

std::ostream& operator << ( std::ostream& out, const Rectangle& obj )
{
	return out;
}

Rectangle::Rectangle()
{

}

Rectangle::operator SDL_Rect ()
{
	return static_cast< SDL_Rect >( SDL_RectWrapper( this->width, this->height ) );
}
