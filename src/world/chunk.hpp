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
public:
	Point2D position;
	tileArray2D tiles;

	Chunk();
};

#endif
