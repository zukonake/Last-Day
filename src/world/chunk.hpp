#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <vector>
//
#include <geometry/point.hpp>
#include <world/tile.hpp>

class Chunk
{
public:
	const static unsigned int sizeInTiles = 32;
private:
	typedef Tile* tileArray2D[ sizeInTiles ][ sizeInTiles ];

	tileArray2D tiles;
public:
	Point2D position;

	Chunk( const Point2D& position );

	Tile& operator()( const Point2D& targetInternalPosition );
};

#endif
