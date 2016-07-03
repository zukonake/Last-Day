#include "entityContainer.hpp"
#include <entity/entity.hpp>

void EntityContainer::addEntity( Entity* value )
{
	entities[ value->getPosition() ] = value;
	return;
}

void EntityContainer::moveEntity( const Point& sourcePosition, const Point& targetPosition )
{
	//entities[ targetPosition ] = entities[ sourcePosition ];
	//entities.erase( sourcePosition );
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

void EntityContainer::simulate( void )
{
	EntityMap2D tempMap;
	for (auto& iterator : entities )
	{
		iterator.second->move( static_cast< Direction::Type >( rand() % 5));
    	tempMap.emplace( iterator.first, iterator.second );
	}
	tempMap.swap( entities );
}

EntityContainer::~EntityContainer( void )
{
	for( auto iterator : entities )
	{
		delete iterator.second;
	}
}
