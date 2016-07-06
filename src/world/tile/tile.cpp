#include "tile.hpp"
#include <exception>
//
#include <world/tile/tileSubtype.hpp>
#include <entity/entity.hpp>

void Tile::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	target.draw( *subtype, states );
	if( entity != nullptr )
	{
		target.draw( *entity, states );
	}
	return;
}

const std::string& Tile::getSubtypeName( void ) const noexcept
{
	return subtype->getName();
}

const int8_t& Tile::getHeight( void ) const noexcept
{
	return height;
}

const bool& Tile::isPassable( void ) const noexcept
{
	return subtype->getIsPassable();
}

std::shared_ptr< Entity > Tile::getEntity( void ) noexcept
{
	return entity;
}

void Tile::setEntity( std::shared_ptr< Entity > value ) noexcept
{
	entity = value;
}
