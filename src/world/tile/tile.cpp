#include "tile.hpp"
#include <exception>
//
#include <world/tile/tileSubtype.hpp>
#include <entity/entity.hpp>

void Tile::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( *pSubtype, states );
	if( pEntity != nullptr )
	{
		target.draw( *pEntity, states );
	}
	return;
}

const std::string& Tile::getSubtypeName( void ) const noexcept
{
	return pSubtype->getName();
}

const int8_t& Tile::getHeight( void ) const noexcept
{
	return mHeight;
}

const bool& Tile::isPassable( void ) const noexcept
{
	return pSubtype->getIsPassable();
}

std::shared_ptr< Entity > Tile::getEntity( void ) noexcept
{
	return pEntity;
}

void Tile::setEntity( std::shared_ptr< Entity > value ) noexcept
{
	pEntity = value;
}
