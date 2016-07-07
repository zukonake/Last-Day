#include "entity.hpp"
#include <entity/entitySubtype.hpp>
#include <world/world.hpp>

Entity::Entity( World& world, const Point& position, const EntitySubtype* subtype ) noexcept :
	mWorld( world ),
	mPosition( position ),
	pSubtype( subtype )
{

}

void Entity::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	if( pSubtype != nullptr )
	{
		target.draw( *pSubtype, states );
	}
	return;
}

void Entity::teleport( const Point& targetPosition ) noexcept
{
	mWorld.moveEntity( mPosition, targetPosition );
	mPosition = targetPosition;
	return;
}

void Entity::move( const Direction& targetDirection )
{
	return;
}

const std::string& Entity::getName( void ) const noexcept
{
	return pSubtype->getName();
}

const Point& Entity::getPosition( void ) const noexcept
{
	return mPosition;
}
