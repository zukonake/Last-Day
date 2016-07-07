#include "tileSubtype.hpp"
#include <exception>

TileSubtype::TileSubtype( std::istream& in ) noexcept :
	RenderableObject( in )
{
	in.ignore( 255, ' ' );
	in >> mName;
	in.ignore( 255, ' ' );
	in >> mIsPassable;
}

const std::string& TileSubtype::getName( void ) const noexcept
{
	return mName;
}

const bool& TileSubtype::getIsPassable( void ) const noexcept
{
	return mIsPassable;
}
