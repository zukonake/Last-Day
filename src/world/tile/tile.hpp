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
	Tile( std::shared_ptr< const TileSubtype > subtype, int8_t height ) noexcept : pSubtype( subtype ), mHeight( height ) { }
	Tile( void ) noexcept : pSubtype( nullptr ) { }

	std::shared_ptr< const TileSubtype > getSubtype( void ) const noexcept;
	void setSubtype( std::shared_ptr< const TileSubtype > value ) noexcept;

	const int8_t& getHeight( void ) const noexcept;
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;

	std::shared_ptr< const TileSubtype > pSubtype;
	int8_t mHeight;
};

#endif
