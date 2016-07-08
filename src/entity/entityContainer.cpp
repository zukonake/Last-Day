#include "entityContainer.hpp"
#include <cstdlib>
#include <memory>
//
#include <geometry/direction.hpp>
#include <entity/entity.hpp>

void EntityContainer::simulate( void ) noexcept
{
	tEntityVector tempVector;
	for( auto iEntity : mEntities )
	{
		tempVector.push_back( iEntity );
	}
	for( auto iEntity : tempVector )
	{
		iEntity->move( static_cast< Direction::eType > ( rand() % 5 ) );
	}
}

std::shared_ptr< Entity > EntityContainer::getEntity( const Point& targetPosition ) noexcept
{
	auto iEntity = std::find_if( mEntities.begin(), mEntities.end(),
    	[ = ]( const std::shared_ptr< Entity >& m) -> bool { return m->getPosition() == targetPosition; } );
	if( iEntity == mEntities.end() )
	{
		return nullptr;
	}
	return *iEntity;
}

void EntityContainer::addEntity( std::shared_ptr< Entity > value )
{
	mEntities.push_back( value );
}
