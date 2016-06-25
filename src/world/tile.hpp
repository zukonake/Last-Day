#ifndef TILE_HPP
#define TILE_HPP

#include <memory>
#include <cstdint>
//
#include <world/tileSubtype.hpp>

class Tile
{
	int8_t height;
	TileSubtype* subtype;
public:
	void render( SDL_Renderer* targetRenderer, SDL_Rect& targetPosition );

	Tile( int8_t height, TileSubtype* subtype );
	Tile();
	~Tile();
};

#endif
