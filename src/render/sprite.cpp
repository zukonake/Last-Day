#include "sprite.hpp"

std::istream& operator >> ( std::istream& in, Sprite& obj )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> ( *obj.sourceImage );
	in >> obj.positionOnImage.x;
	in >> obj.positionOnImage.y;
	in >> obj.positionOnImage.w;
	in >> obj.positionOnImage.h;
	return in;
}

std::ostream& operator << ( std::ostream& out, const Sprite& obj )
{
	return out;
}

Sprite::Sprite() : sourceImage( new Image() )
{

}
