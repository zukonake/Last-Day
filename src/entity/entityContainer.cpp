#include "entityContainer.hpp"
#include <cstdlib>
#include <memory>
//
#include <geometry/direction.hpp>
#include <entity/entity.hpp>

void EntityContainer::moveEntity( const Point& sourcePosition, const Point& targetPosition ) noexcept
{
	mEntities[ targetPosition ] = mEntities[ sourcePosition ];
	mEntities.erase( sourcePosition );
	return;
}

void EntityContainer::simulate( void ) noexcept
{
	tEntityMap tempMap = mEntities;
	for( auto& iEntity : tempMap )
	{
		iEntity.second->move( static_cast< Direction::eType > ( rand() % 5 ) );
	}
	return;
}

std::shared_ptr< Entity > EntityContainer::getEntity( const Point& targetPosition ) noexcept
{
	if( mEntities.find( targetPosition ) == mEntities.end() )
	{
		return nullptr;
	}
	return mEntities[ targetPosition ];
}

void EntityContainer::addEntity( std::shared_ptr< Entity > value )
{
	mEntities[ value->getPosition() ] = value;
	return;
}

void EntityContainer::removeEntity( const Point& targetPosition ) noexcept
{
	if( mEntities.find( targetPosition ) == mEntities.end() )
	{
		return;
	}
	mEntities[ targetPosition ].reset();
	mEntities.erase( targetPosition );
	return;
}
