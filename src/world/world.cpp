#include "world.hpp"
#include <SFML/Graphics.hpp>
//
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <data/dataset.hpp>
#include <world/worldGenerator.hpp>
#include <core/player.hpp>

World::World( const Dataset& dataset, const int& seed ) noexcept :
	EntityContainer(),
	ChunkContainer( mGenerator, static_cast< EntityContainer& >( *this ) ),
	mDataset( dataset ),
	mGenerator( *this, mDataset, seed )
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

Player* World::createPlayer( const Point& position, const Rectangle& screenSize ) noexcept
{
	return new Player( position, *this, screenSize, mDataset );
}
