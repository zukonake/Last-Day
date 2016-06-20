#ifndef WORLD_HPP
#define WORLD_HPP

#include <string>
#include <vector>
//
#include <geometry/point.hpp>
#include <world/tile.hpp>
#include <world/chunk.hpp>
#include <world/worldGenerator.hpp>

class World
{
	typedef std::vector< Chunk* > ChunkVector;
	const static unsigned int chunkLoadingRange = 3;
	std::string name;
	ChunkVector loadedChunks;
	WorldGenerator* generator;
	Chunk* getChunk( const Point2D& targetTilePosition );
	Chunk* loadChunk( const Point2D& targetChunkPosition );
public:
	Tile* operator()( const Point2D& targetTilePosition );
	World();
};

#endif
