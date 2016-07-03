#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include <noise/noise.h>
//
#include <geometry/point.hpp>
#include <world/chunk/chunk.hpp>
#include <data/dataset.hpp>
#include <entity/entityContainer.hpp>
#include <world/tile/tile.hpp>

class World;

class WorldGenerator
{
	constexpr static double scale = 15;
	constexpr static double heightMultiplier = 10;
public:
	WorldGenerator( Dataset& availableDataset, EntityContainer& entityContainer ) noexcept;

	Chunk& generateChunk( World& world, Chunk& target, const Point& targetChunkPosition ) noexcept;
	Tile& generateTile( World& world, Tile& target, const Point& targetTilePosition ) noexcept;

	static int getMaximumTileHeight()
	{
		return ( int )( heightMultiplier );
	}
private:
	Dataset& availableDataset;
	EntityContainer& entityContainer;

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
};

#endif
