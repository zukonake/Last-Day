#include "world.hpp"
#include <SFML/Graphics.hpp>
//
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <data/dataset.hpp>
#include <world/worldGenerator.hpp>

World::World( const Dataset& dataset ) noexcept :
	ChunkContainer( generator ),
	EntityContainer( dynamic_cast< ChunkContainer& >( *this )),
	dataset( dataset ),
	generator( *this )
{

}

void World::simulate( void ) noexcept
{
	EntityContainer::simulate();
	return;
}

const Dataset& World::getDataset( void ) const noexcept
{
	return dataset;
}

const WorldGenerator& World::getGenerator( void ) const noexcept
{
	return generator;
}
