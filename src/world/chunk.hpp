#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <world/tile.hpp>

struct Chunk
{
	const static unsigned int sizeInTiles = 128;
	typedef Tile tileArray2D[ sizeInTiles ][ sizeInTiles ];

	tileArray2D tiles;
};

#endif
