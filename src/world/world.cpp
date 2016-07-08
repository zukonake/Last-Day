#include "world.hpp"
#include <SFML/Graphics.hpp>
//
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <data/dataset.hpp>
#include <world/worldGenerator.hpp>
#include <entity/camera.hpp>

World::World( const Dataset& dataset, const int& seed ) noexcept :
	EntityContainer(),
	ChunkContainer( mGenerator, static_cast< EntityContainer& >( *this ) ),
	mGenerator( *this, dataset, seed )
{

}

void World::simulate( void ) noexcept
{
	EntityContainer::simulate();
	ChunkContainer::unloadInactiveChunks();
	return;
}

bool World::canMove( const Point& target ) noexcept
{
	return getEntity( target ) == nullptr and getTile( target ).isPassable();
}

Camera* World::createCamera( const Point& position, const Rectangle& screenSize ) noexcept
{
	return new Camera( position, *this, screenSize );
}
