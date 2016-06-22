#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include <world/tile.hpp>
#include <world/chunk.hpp>
#include <data/dataset.hpp>

class WorldGenerator
{
public:
	Chunk generateChunk( const Dataset& availableDataset );

	WorldGenerator();
};

#endif
