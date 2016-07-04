#ifndef TILE_HPP
#define TILE_HPP

#include <cstdint>
//
#include <world/tile/tileSubtype.hpp>
#include <render/objectRenderer/objectRenderer.hpp>

class Tile
{
public:
	Tile( const TileSubtype* subtype, int8_t height ) noexcept : subtype( subtype ), height( height ) { }
	Tile( void ) noexcept : subtype( nullptr ) { }

	virtual void render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const;

	const std::string& getSubtypeName( void ) const noexcept;
	const int8_t& getHeight( void ) const noexcept;
private:
	const TileSubtype* subtype;
	int8_t height;
};

#endif
