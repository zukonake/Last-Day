#ifndef TILE_HPP
#define TILE_HPP

#include <memory>
#include <cstdint>
#include <string>
#include <SFML/Graphics.hpp>

struct Point;
class TileSubtype;
class Entity;
class World;

class Tile : public sf::Drawable
{
public:
	Tile( const TileSubtype* subtype, int8_t x ) noexcept : pSubtype( subtype ), mHeight( x ) { }
	Tile( void ) noexcept : pSubtype( nullptr ) { }

	const TileSubtype* getSubtype( void ) const noexcept;
	void setSubtype( const TileSubtype* value ) noexcept;

	const int8_t& getHeight( void ) const noexcept;
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;

	const TileSubtype* pSubtype;
	int8_t mHeight;
};

#endif
