#ifndef CHUNKCONTAINER_HPP
#define CHUNKCONTAINER_HPP

#include <cstdint>
#include <memory>
#include <map>
//
#include <geometry/point.hpp>
#include <world/chunk/chunk.hpp>

class Tile;
class EntityContainer;
class WorldGenerator;

class ChunkContainer
{
	typedef std::map< const Point, Chunk > tChunkMap;
	const static uint8_t csChunkActiveRange = 2;
	const static uint8_t csChunkActiveThreshold = 5;
public:
	ChunkContainer( const WorldGenerator& generator, EntityContainer& entityContainer ) noexcept;

	virtual ~ChunkContainer( void ) = default;

	void unloadInactiveChunks( void ) noexcept;

	Tile& getTile( const Point& targetTilePosition, const bool& chunkAnchor = false ) noexcept;
private:
	Chunk& getChunk( const Point& targetChunkPosition, const bool& chunkAnchor = false ) noexcept;
	void setNearbyChunksActive( const Point& targetChunkPosition ) noexcept;
	Chunk& loadChunk( const Point& targetChunkPosition ) noexcept;
	void unloadChunk( const Point& targetChunkPosition ) noexcept;

	tChunkMap mLoadedChunks;
	const WorldGenerator& mGenerator;
	EntityContainer& mEntityContainer;
};

#endif
