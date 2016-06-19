#ifndef WORLD_HPP
#define WORLD_HPP

#include <string>
#include <vector>
//
#include <geometry/point.hpp>
#include <world/tile.hpp>
#include <world/chunk.hpp>
#include <world/worldGenerator.hpp>

class World
{
	typename std::vector< std::vector< Chunk* > > ChunkVector2D
	std::string name;
	ChunkVector2D value;
	WorldGenerator* generator;
	Tile* operator( Point2D targetPosition );
	World();
};

#endif
