#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include <noise/noise.h>

struct Point;
struct Chunk;
class Tile;
class World;
class Dataset;

class WorldGenerator
{
	constexpr static double csScale = 75;
	constexpr static double csHeightMultiplier = 10;
public:
	WorldGenerator( World& world, const Dataset& dataset, const int& seed ) noexcept;

	Chunk& generateChunk( const Point& targetChunkPosition, Chunk& target ) const noexcept;
	Tile& generateTile( const Point& targetTilePosition, Tile& target ) const noexcept;

	const int& getSeed( void ) const noexcept;
	static int getMaximumTileHeight( void )
	{
		return ( int )( csHeightMultiplier );
	}
private:
	World& mWorld;
	const Dataset& mDataset;
	int mSeed;

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
