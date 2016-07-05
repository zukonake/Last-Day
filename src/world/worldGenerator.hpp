#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include <noise/noise.h>

struct Point;
struct Chunk;
class Tile;
class World;

class WorldGenerator
{
	constexpr static double scale = 20;
	constexpr static double heightMultiplier = 10;
public:
	WorldGenerator( World& world ) noexcept;

	Chunk& generateChunk( const Point& targetChunkPosition, Chunk& target ) const noexcept;
	Tile& generateTile( const Point& targetTilePosition, Tile& target ) const noexcept;

	static int getMaximumTileHeight()
	{
		return ( int )( heightMultiplier );
	}
private:
	World& world;

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
