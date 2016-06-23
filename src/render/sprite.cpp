#include "sprite.hpp"

void Sprite::render( SDL_Surface& targetSurface, SDL_Rect& targetPosition )
{
	Image::render( positionOnImage, targetSurface, targetPosition );
	//std::cout << "INFO: Rendering sprite.\n";
}

Sprite::Sprite( std::istream& in ) :
	Image( in )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> positionOnImage.x;
	in >> positionOnImage.y;
	in >> positionOnImage.w;
	in >> positionOnImage.h;
	std::cout << "INFO: Initializing sprite.\n";
}

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}
