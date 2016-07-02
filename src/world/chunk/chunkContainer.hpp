#ifndef CHUNKCONTAINER_HPP
#define CHUNKCONTAINER_HPP

#include <cstdint>
#include <map>
#include <memory>
//
#include <geometry/point.hpp>
#include <data/dataset.hpp>
#include <entity/entityContainer.hpp>
#include <world/tile/tile.hpp>
#include <world/chunk/chunk.hpp>
#include <world/worldGenerator.hpp>

class World;

class ChunkContainer
{
	typedef std::map< Point, Chunk > ChunkMap2D;
	const static uint8_t chunkLoadingRange = 1;

	ChunkMap2D loadedChunks;
	World& world;
	WorldGenerator generator;
public:
	Tile& getTile( const Point& targetTilePosition );

	Chunk& getChunk( const Point& targetChunkPosition );
private:
	Chunk& loadChunk( const Point& targetChunkPosition );
public:
	ChunkContainer( World& world, Dataset& availableDataset, EntityContainer& entityContainer ) : world( world ), generator( availableDataset, entityContainer ) { }
	virtual ~ChunkContainer( void );
private:
	void unloadChunks( void );
	void unloadChunk( const Point& targetChunkPosition );
};

#endif
