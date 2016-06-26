#ifndef TILE_HPP
#define TILE_HPP

#include <exception>
#include <memory>
#include <cstdint>
//
#include <world/tileSubtype.hpp>
#include <render/objectRenderer/objectRenderer.hpp>

class Tile
{
	TileSubtype* subtype;
	int8_t height;
public:
	virtual void render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const;

	const int8_t& getHeight( void ) const noexcept { return height; }

	Tile( TileSubtype* subtype, int8_t height ) noexcept : subtype( subtype ), height( height ) { }
	Tile( void ) noexcept : subtype( NULL ) { }
};

#endif
