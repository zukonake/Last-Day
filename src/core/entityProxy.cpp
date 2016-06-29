#include "entityProxy.hpp"

void EntityProxy::addEntity( Entity* target )
{
	if( target == NULL )
	{
		throw std::invalid_argument( "ERROR: EntityProxy::addEntity null pointer given in argument 1." );
		return;
	}
	entities.push_back( target );
	return;
}

void EntityProxy::removeEntity( Entity* target )
{
	if( target == NULL )
	{
		throw std::invalid_argument( "ERROR: EntityProxy::removeEntity null pointer given in argument 1." );
		return;
	}
	if( findEntity( target->getPosition() ) != NULL )
	{
		delete target;
	}
	return;
}

Entity* EntityProxy::findEntity( const Point& targetPosition ) const
{
	for( auto iterator : entities )
	{
		if( iterator->getPosition() == targetPosition )
		{
			return iterator;
		}
	}
	return NULL;
}

EntityProxy::~EntityProxy( void ) noexcept
{
	for( auto iterator : entities )
	{
		removeEntity( iterator );
	}
}
