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

	static Point2D transformPositionToChunkPosition( const Point2D& targetTilePosition );
	static Point2D transformPositionToInternalPosition( const Point2D& targetTilePosition );
	static Point2D transformPositionToTilePosition( const Point2D& targetChunkPosition );

	Chunk( const Point2D& position );
	
	Tile* operator()( const Point2D& targetInternalPosition );
};

#endif
