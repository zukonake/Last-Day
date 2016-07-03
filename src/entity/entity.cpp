#include "entity.hpp"
#include <world/world.hpp>

Entity::Entity( World& world, const Point& position, EntitySubtype* subtype ) noexcept :
	world( world ),
	position( position ),
	subtype( subtype )
{

}

void Entity::render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const
{
	if( subtype != nullptr )
	{
		subtype->render( renderer, targetPosition );
	}
}

void Entity::teleport( const Point& targetPosition ) noexcept
{
	world.moveEntity( position, targetPosition );
	position = targetPosition;
}

void Entity::move( const Direction& targetDirection ) noexcept
{
	Point positionBefore = getPosition();
	position.move( targetDirection );
	world.moveEntity( positionBefore, position );
}

const std::string& Entity::getName( void ) const noexcept
{
	return subtype->getName();
}

const Point& Entity::getPosition( void ) const noexcept
{
	return position;
}
