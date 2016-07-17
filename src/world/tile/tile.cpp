#include "tile.hpp"
#include <exception>
//
#include <world/tile/tileSubtype.hpp>
#include <entity/entity.hpp>

const TileSubtype* Tile::getSubtype( void ) const noexcept
{
	return pSubtype;
}

void Tile::setSubtype( const TileSubtype* value ) noexcept
{
	pSubtype = value;
	return;
}

void Tile::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( *pSubtype, states );
	return;
}

const int8_t& Tile::getHeight( void ) const noexcept
{
	return mHeight;
}
