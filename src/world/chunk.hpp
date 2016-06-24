#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <memory>
//
#include <geometry/point.hpp>
#include <world/tile.hpp>

struct Chunk
{
	const static unsigned int sizeInTiles = 32;
	typedef Tile* tileArray2D[ sizeInTiles ][ sizeInTiles ];

	tileArray2D tiles;

	Chunk();
};

#endif
