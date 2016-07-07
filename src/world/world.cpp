#include "world.hpp"
#include <SFML/Graphics.hpp>
//
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <data/dataset.hpp>
#include <world/worldGenerator.hpp>

World::World( const Dataset& dataset, const int& seed ) noexcept :
	ChunkContainer( mGenerator ),
	EntityContainer( dynamic_cast< ChunkContainer& >( *this )),
	mDataset( dataset ),
	mGenerator( *this, seed )
{

}

void World::simulate( void ) noexcept
{
	EntityContainer::simulate();
	return;
}

const Dataset& World::getDataset( void ) const noexcept
{
	return mDataset;
}

const WorldGenerator& World::getGenerator( void ) const noexcept
{
	return mGenerator;
}

const int& World::getSeed( void ) const noexcept
{
	return mGenerator.getSeed();
}
