#ifndef WORLD_HPP
#define WORLD_HPP

#include <string>
#include <vector>
//
#include <geometry/point.hpp>
#include <world/tile.hpp>
#include <world/chunk.hpp>
#include <data/dataset.hpp>
#include <world/worldGenerator.hpp>

class World
{
	typedef std::vector< Chunk > ChunkVector;
	const static unsigned int chunkLoadingRange = 3;

	std::string name;
	ChunkVector loadedChunks;
	WorldGenerator generator;
	const Dataset& dataset;

	static Point2D transformPositionToChunkPosition( const Point2D& targetTilePosition );
	static Point2D transformPositionToInternalPosition( const Point2D& targetTilePosition );
	static Point2D transformPositionToTilePosition( const Point2D& targetChunkPosition );
protected:
	Chunk& getChunk( const Point2D& targetTilePosition );
	Chunk& loadChunk( const Point2D& targetChunkPosition );
public:
	World( const Dataset& dataset );
	~World();

	Tile& operator()( const Point2D& targetTilePosition );
};

#endif
