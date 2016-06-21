#include "sprite.hpp"

std::istream& operator >> ( std::istream& in, Sprite& obj )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> dynamic_cast< Image& >( obj );
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

void Sprite::render( UserInterface* targetUserInterface, SDL_Rect* targetPosition )
{
	Image::render( &positionOnImage, dynamic_cast< SDL_Surface* >( targetUserInterface ), targetPosition );
}

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}
