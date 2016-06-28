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
	noise::module::Billow seaTerrain;
	noise::module::Billow flatTerrain;
	noise::module::RidgedMulti mountainTerrain;
	noise::module::Perlin terrainType;
	noise::module::ScaleBias scaledSeaTerrain;
	noise::module::ScaleBias scaledFlatTerrain;
	noise::module::ScaleBias scaledMountainTerrain;
	noise::module::ScaleBias scaledTerrainType;
	noise::module::Add seaBed;
	noise::module::Select terrainSelector;
	noise::module::Select landTerrainSelector;
	noise::module::Turbulence finalTerrain;
	const double scale = 15;
	const double heightMultiplier = 10;
	double flatness;
public:
	Chunk& generateChunk( Chunk& target, Dataset& availableDataset, const Point& targetChunkPosition );
	int getMaximumTileHeight();

	WorldGenerator();
};

#endif
