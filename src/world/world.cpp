#include "world.hpp"
#include <SFML/Graphics.hpp>
//
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <data/dataset.hpp>
#include <world/worldGenerator.hpp>
#include <entity/camera.hpp>

World::World( const Dataset& dataset, const int& seed ) noexcept :
	ChunkContainer( mGenerator ),
	EntityContainer( dynamic_cast< ChunkContainer& >( *this )),
	mGenerator( *this, dataset, seed )
{

}

void World::simulate( void ) noexcept
{
	EntityContainer::simulate();
	return;
}

Camera* World::createCamera( const Point& position, const Rectangle& screenSize ) noexcept
{
	return new Camera( position, *this, screenSize );
}
