#include "entity.hpp"
#include <entity/entitySubtype.hpp>
#include <world/world.hpp>

Entity::Entity( const Point& position, std::shared_ptr< const EntitySubtype > subtype, World& world ) noexcept :
	mPosition( position ),
	pSubtype( subtype ),
	mWorld( world )
{

}

std::shared_ptr< const EntitySubtype > Entity::getSubtype( void ) const noexcept
{
	return pSubtype;
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
	mPosition = targetPosition;
	return;
}

void Entity::move( const Direction& targetDirection )
{
	return;
}

const Point& Entity::getPosition( void ) const noexcept
{
	return mPosition;
}
