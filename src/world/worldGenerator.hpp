#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include <world/chunk.hpp>
#include <data/dataset.hpp>

class WorldGenerator
{
public:
	Chunk::tileArray2D& generateTileArray2D( Chunk::tileArray2D& target, Dataset& availableDataset );

	WorldGenerator();
};

#endif
