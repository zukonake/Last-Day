#include "tile.hpp"

std::istream& operator >> (std::istream& in, Tile& obj )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> obj.name;
	in >> dynamic_cast< Sprite& >( obj );
	in >> obj.isPassable;
	return in;
}

std::ostream& operator << (std::ostream& out, const Tile& obj )
{
	return out;
}

Tile::Tile() : Sprite()
{

}

Tile::~Tile()
{

}
