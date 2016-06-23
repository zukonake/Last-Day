#include "tile.hpp"

Tile::Tile( std::istream& in ) :
	Sprite( in )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> name;
	std::cout << "INFO: Initializing tile: " << name << ".\n";
	in >> isPassable;
}

Tile::Tile()
{

}

Tile::~Tile()
{

}
