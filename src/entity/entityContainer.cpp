#include "entityContainer.hpp"
#include <cstdlib>
#include <memory>
//
#include <geometry/direction.hpp>
#include <entity/entity.hpp>

void EntityContainer::simulate( void ) noexcept
{
	tEntityMap tempMap;
	for( auto iEntity : mEntities )
	{
		tempMap[ iEntity.second->getPosition() ] = iEntity.second;
	}
	for( auto iEntity : tempMap )
	{
		iEntity.second->move( static_cast< Direction::eType > ( rand() % 5 ) );
	}
	tempMap.swap( mEntities );
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
}
