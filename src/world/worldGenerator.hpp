#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include <memory>
#include <cstdlib>
#include <noise/noise.h>
//
#include <geometry/point.hpp>
#include <world/chunk/chunk.hpp>
#include <data/dataset.hpp>
#include <entity/entityContainer.hpp>

class World;

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
	constexpr static double scale = 15;
	constexpr static double heightMultiplier = 10;
	double flatness;
	Dataset& availableDataset;
	EntityContainer& entityContainer;
public:
	Chunk& generateChunk( World& world, Chunk& target, const Point& targetChunkPosition );
	static int getMaximumTileHeight()
	{
		return ( int )( heightMultiplier );
	}

	WorldGenerator( Dataset& availableDataset, EntityContainer& entityContainer );
};

#endif
