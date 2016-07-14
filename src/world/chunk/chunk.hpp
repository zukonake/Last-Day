#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <cstdint>
#include <array>
//
#include <world/tile/tile.hpp>

struct Chunk
{
	const static uint16_t sizeInTiles = 64;
	typedef std::array< std::array< Tile, sizeInTiles >, sizeInTiles > TileArray2D;

	int active = 0;
	TileArray2D value;
};

#endif
