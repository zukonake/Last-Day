#include "tileSubtype.hpp"
#include <exception>

uint8_t TileSubtype::spriteSize = 32;

TileSubtype::TileSubtype( std::istream& in ) noexcept :
	RenderableObject( in )
{
	in.ignore( 255, ' ' );
	in >> name;
	in.ignore( 255, ' ' );
	in >> isPassable;
}

const std::string& TileSubtype::getName( void ) const noexcept
{
	return name;
}

const bool& TileSubtype::getIsPassable( void ) const noexcept
{
	return isPassable;
}
