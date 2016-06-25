#include "tileSubtype.hpp"

unsigned int TileSubtype::spriteSize = 32;

TileSubtype::TileSubtype( std::istream& in ) :
	Image( in )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> name;
	std::cout << "INFO: Initializing tile: " << name << ".\n";
	in >> isPassable;
}

TileSubtype::TileSubtype()
{

}

TileSubtype::~TileSubtype()
{

}
