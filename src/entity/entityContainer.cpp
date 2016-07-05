#include "entityContainer.hpp"
#include <cstdlib>
#include <memory>
//
#include <geometry/direction.hpp>
#include <entity/entity.hpp>

void EntityContainer::simulate( void ) noexcept
{
	std::vector< std::shared_ptr< Entity > > tempVector;
	for( auto iterator : entities )
	{
		tempVector.push_back( iterator );
	}
	for( auto iterator : tempVector )
	{
		iterator->move( static_cast< Direction::Type > ( rand() % 5 ) );
	}
}

void EntityContainer::addEntity( std::shared_ptr< Entity > value )
{
	entities.push_back( value );
	chunkContainer.getTile( value->getPosition() ).setEntity( value );
}
