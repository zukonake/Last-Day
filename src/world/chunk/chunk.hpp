#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <cstdint>
//
#include <world/tile/tile.hpp>

struct Chunk
{
	const static uint16_t sizeInTiles = 64;
	typedef Tile TileArray2D[ sizeInTiles ][ sizeInTiles ];

	static uint16_t getSizeInTiles( void )
	{
		return sizeInTiles;
	}

	int active = 0;
	TileArray2D value;
};

#endif
