#include "entityContainer.hpp"
#include <entity/entity.hpp>

EntityContainer::~EntityContainer( void ) noexcept
{
	for( auto iterator : entities )
	{
		delete iterator.second;
	}
}

void EntityContainer::addEntity( Entity* value ) noexcept
{
	entities[ value->getPosition() ] = value;
	return;
}

void EntityContainer::moveEntity( const Point& sourcePosition, const Point& targetPosition ) noexcept
{
	//entities[ targetPosition ] = entities[ sourcePosition ];
	//entities.erase( sourcePosition ); TODO
	return;
}

Entity* EntityContainer::getEntity( const Point& targetPosition ) noexcept
{
	if( entities.find( targetPosition ) == entities.end() )
	{
		return nullptr;
	}
	return entities[ targetPosition ];
}

void EntityContainer::simulate( void ) noexcept
{
	EntityMap2D tempMap; //TODO wip
	for (auto& iterator : entities )
	{
		iterator.second->move( static_cast< Direction::Type >( rand() % 5));
    	tempMap.emplace( iterator.first, iterator.second );
	}
	tempMap.swap( entities );
}
