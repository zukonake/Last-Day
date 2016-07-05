#include "entity.hpp"
#include <entity/entitySubtype.hpp>
#include <world/world.hpp>

Entity::Entity( World& world, const Point& position, const EntitySubtype* subtype ) noexcept :
	world( world ),
	position( position ),
	subtype( subtype )
{

}

void Entity::render( sf::RenderWindow& window, const Point& targetPosition ) const
{
	if( subtype != nullptr )
	{
		subtype->render( window, targetPosition );
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
