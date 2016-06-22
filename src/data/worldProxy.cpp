#include "worldProxy.hpp"

void WorldProxy::initializeWorld()
{

}

void WorldProxy::simulate()
{

}

Player WorldProxy::createPlayer( const Point2D& position )
{
	return Player( position, dynamic_cast< World& >( *this ), initializedMobSubtypes[ "human" ] );
}

WorldProxy::WorldProxy() : World( dynamic_cast< Dataset& >( *this ) )
{
	initializeWorld();
}
