#include "entity.hpp"
#include <entity/entitySubtype.hpp>
#include <world/world.hpp>

Entity::Entity( World& world, const Point& position, const EntitySubtype* subtype ) noexcept :
	world( world ),
	position( position ),
	subtype( subtype )
{

}

void Entity::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	if( subtype != nullptr )
	{
		target.draw( *subtype, states );
	}
	return;
}

void Entity::teleport( const Point& targetPosition ) noexcept
{
	world.moveEntity( position, targetPosition );
	position = targetPosition;
	return;
}

void Entity::move( const Direction& targetDirection )
{
	return;
}

const std::string& Entity::getName( void ) const noexcept
{
	return subtype->getName();
}

const Point& Entity::getPosition( void ) const noexcept
{
	return position;
}
