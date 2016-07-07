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

void EntityContainer::addEntity( std::shared_ptr< Entity > value )
{
	mEntities.push_back( value );
	mChunkContainer.getTile( value->getPosition() ).setEntity( value );
}
