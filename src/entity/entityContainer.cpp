#include "entityContainer.hpp"
#include <entity/entity.hpp>

void EntityContainer::addEntity( Entity* value )
{
	entities[ value->getPosition() ] = value;
	return;
}

void EntityContainer::moveEntity( const Point& sourcePosition, const Point& targetPosition )
{
	entities[ targetPosition ] = entities[ sourcePosition ];
	entities[ sourcePosition ] = nullptr;
	return;
}

Entity* EntityContainer::getEntity( const Point& targetPosition )
{
	if( entities.find( targetPosition ) == entities.end() )
	{
		return nullptr;
	}
	return entities[ targetPosition ];
}

EntityContainer::~EntityContainer( void )
{
	for( auto iterator : entities )
	{
		delete iterator.second;
	}
}
