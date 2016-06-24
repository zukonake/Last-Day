#ifndef WORLD_HPP
#define WORLD_HPP

#include <memory>
#include <vector>
//
#include <geometry/point.hpp>
#include <world/tile.hpp>
#include <world/chunk.hpp>
#include <data/dataset.hpp>
#include <world/worldGenerator.hpp>

class World
{
	typedef std::vector< std::shared_ptr< Chunk > > ChunkVector;
	const static uint8_t chunkLoadingRange = 1;

	ChunkVector loadedChunks;
	WorldGenerator generator;
	Dataset& dataset;

	static Point transformPositionToChunkPosition( const Point& targetTilePosition );
	static Point transformPositionToInternalPosition( const Point& targetTilePosition );
protected:
	std::shared_ptr< Chunk > getChunk( const Point& targetTilePosition );
	std::shared_ptr< Chunk > loadChunk( const Point& targetChunkPosition );
	void unloadChunk( uint16_t id );
public:
	World( Dataset& dataset );
	~World();

	Tile* operator()( const Point& targetTilePosition );
};

#endif
