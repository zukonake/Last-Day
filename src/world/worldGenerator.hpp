#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include <cstdlib>
//
#include <world/chunk.hpp>
#include <data/dataset.hpp>

class WorldGenerator
{
public:
	Chunk& generateChunk( Chunk& target, Dataset& availableDataset );

	WorldGenerator();
};

#endif
