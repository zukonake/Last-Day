#ifndef TILE_HPP
#define TILE_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

struct Point;
class TileSubtype;
class Entity;

class Tile
{
public:
	Tile( const TileSubtype* subtype, int8_t height ) noexcept : subtype( subtype ), height( height ), entity( nullptr ) { }
	Tile( void ) noexcept : subtype( nullptr ), entity( nullptr ) { }

	void render( sf::RenderWindow& window, const Point& targetPosition ) const;

	const std::string& getSubtypeName( void ) const noexcept;
	const int8_t& getHeight( void ) const noexcept;
	const bool& isPassable( void ) const noexcept;
	std::shared_ptr< Entity > getEntity( void ) noexcept;
	void setEntity( std::shared_ptr< Entity > value ) noexcept;
private:
	const TileSubtype* subtype;
	int8_t height;
	std::shared_ptr< Entity > entity;
};

#endif
