#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <world/tile.hpp>

struct Chunk
{
	const static unsigned int sizeInTiles = 128;
	typedef Tile TileArray2D[ sizeInTiles ][ sizeInTiles ];

	TileArray2D tiles;
};

#endif
