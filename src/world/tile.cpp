#include "tile.hpp"

std::istream& operator >> (std::istream& in, Tile& obj )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> obj.name;
	in >> ( *obj.sprite );
	in >> obj.isPassable;
	return in;
}

std::ostream& operator << (std::ostream& out, const Tile& obj )
{
	return out;
}

void Tile::render( Interface* targetInterface, SDL_Rect* targetPosition )
{
	sprite->render( targetInterface, targetPosition );
}

Tile::Tile() : sprite( new Sprite() )
{

}
