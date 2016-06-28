#include "entity.hpp"

void Entity::render( ObjectRenderer* renderer, const Point& targetPosition ) const
{
	if( subtype != NULL )
	{
		subtype->render( renderer, targetPosition );
	}
}

void Entity::teleport( const Point& targetPosition ) noexcept
{
	position = targetPosition;
}

void Entity::move( const Direction& targetDirection ) noexcept
{
	position.move( targetDirection );
}
