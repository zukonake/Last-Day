#include "entity.hpp"
#include <entity/entitySubtype.hpp>
#include <world/world.hpp>

Entity::Entity( World& world, const Point& position, const EntitySubtype* subtype ) noexcept :
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

void Entity::DEBUG( void ) { world.moveEntity( position, Point( position.x - 1, position.y ) ); position.x = position.x - 1; } //TODO

const std::string& Entity::getName( void ) const noexcept
{
	return subtype->getName();
}

const Point& Entity::getPosition( void ) const noexcept
{
	return position;
}
