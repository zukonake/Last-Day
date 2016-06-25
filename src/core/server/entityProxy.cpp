#include "entityProxy.hpp"

Entity< EntitySubtype >* EntityProxy::addEntity( Entity< EntitySubtype >* entity )
{
	entities[ entity->position.x ][ entity->position.y ].reset( entity );
	return entities[ entity->position.x ][ entity->position.y ].get();
}

Entity< EntitySubtype >* EntityProxy::removeEntity( const Point& targetPosition )
{

}

Entity< EntitySubtype >* EntityProxy::getEntityOnTile( const Point& targetPosition )
{

}

EntityProxy::EntityProxy()
{

}
