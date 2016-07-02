#include "entity.hpp"
#include <world/world.hpp>

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

Entity::Entity( EntitySubtype* subtype, World& world, const Point& position ) noexcept :
	subtype( subtype ),
	world( world ),
	position( position )
{

}
