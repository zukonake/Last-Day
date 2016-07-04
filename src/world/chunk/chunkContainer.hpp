#ifndef CHUNKCONTAINER_HPP
#define CHUNKCONTAINER_HPP

#include <cstdint>
#include <map>
//
#include <geometry/point.hpp>
#include <world/tile/tile.hpp>
#include <world/chunk/chunk.hpp>
#include <world/worldGenerator.hpp>

class ChunkContainer
{
	typedef std::map< Point, Chunk > ChunkMap2D;
	const static uint8_t chunkLoadingRange = 1;
public:
	ChunkContainer( WorldGenerator& generator ) noexcept;
	virtual ~ChunkContainer( void ) noexcept { };

	Tile& getTile( const Point& targetTilePosition );

	Chunk& getChunk( const Point& targetChunkPosition );
private:
	Chunk& loadChunk( const Point& targetChunkPosition );

	ChunkMap2D loadedChunks;
	WorldGenerator& generator;
};

#endif
