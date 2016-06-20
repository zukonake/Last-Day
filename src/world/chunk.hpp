#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <vector>
//
#include <geometry/point.hpp>
#include <world/tile.hpp>

class Chunk
{
	friend class World;
	const static unsigned int chunkSizeInTiles = 32;
	typedef Tile* tileArray2D[ chunkSizeInTiles ][ chunkSizeInTiles ];
	Point2D position;
	tileArray2D tiles;
	static inline Point2D transformPositionToChunkPosition( Point2D targetTilePosition );
	static inline Point2D transformPositionToInternalPosition( Point2D targetTilePosition );
	static inline Point2D transformPositionToTilePosition( Point2D targetChunkPosition );
	Tile* operator()( Point2D targetInternalPosition );
	Chunk( Point2D position );
};

inline Point2D Chunk::transformPositionToChunkPosition( Point2D targetTilePosition )
{
	Point2D output = targetTilePosition * chunkSizeInTiles;
	return output;
}

inline Point2D Chunk::transformPositionToInternalPosition( Point2D targetTilePosition )
{
	Point2D output = targetTilePosition % chunkSizeInTiles;
	return output;
}

inline Point2D Chunk::transformPositionToTilePosition( Point2D targetChunkPosition )
{
	Point2D output = targetChunkPosition / chunkSizeInTiles;
	return output;
}


#endif
