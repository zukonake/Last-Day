#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include <iomanip>
#include <cstdlib>
#include <noise/noise.h>
//
#include <geometry/point.hpp>
#include <world/chunk.hpp>
#include <data/dataset.hpp>

class WorldGenerator
{
	noise::module::Perlin perlinNoise;
public:
	Chunk& generateChunk( Chunk& target, Dataset& availableDataset, const Point& targetChunkPosition );

	WorldGenerator();
};

#endif
