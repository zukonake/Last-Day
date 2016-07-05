#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <cstdint>
//
#include <world/tile/tile.hpp>

struct Chunk
{
	const static uint8_t sizeInTiles = 64;
	typedef Tile TileArray2D[ sizeInTiles ][ sizeInTiles ];

	TileArray2D tiles;
};

#endif
