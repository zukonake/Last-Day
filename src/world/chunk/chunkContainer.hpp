#ifndef CHUNKCONTAINER_HPP
#define CHUNKCONTAINER_HPP

#include <cstdint>
#include <map>
//
#include <geometry/point.hpp>
#include <world/chunk/chunk.hpp>

class Tile;
class WorldGenerator;

class ChunkContainer
{
	typedef std::map< const Point, Chunk > ChunkMap2D;
	const static uint8_t chunkLoadingRange = 1;
public:
	ChunkContainer( WorldGenerator& generator ) noexcept;
	virtual ~ChunkContainer( void ) noexcept { };

	void moveEntity( const Point& sourcePosition, const Point& targetPosition );
	bool canMove( const Point& targetPosition );

	Tile& getTile( const Point& targetTilePosition );
private:
	Chunk& getChunk( const Point& targetChunkPosition );
	Chunk& loadChunk( const Point& targetChunkPosition );

	ChunkMap2D loadedChunks;
	WorldGenerator& generator;
};

#endif
