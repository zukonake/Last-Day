#ifndef TILE_HPP
#define TILE_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

struct Point;
class TileSubtype;
class Entity;
class World;

class Tile : public sf::Drawable
{
public:
	Tile( const TileSubtype* subtype, int8_t height ) noexcept : pSubtype( subtype ), mHeight( height ), pEntity( nullptr ) { }
	Tile( void ) noexcept : pSubtype( nullptr ), pEntity( nullptr ) { }

	const std::string& getSubtypeName( void ) const noexcept;
	const int8_t& getHeight( void ) const noexcept;
	const bool& isPassable( void ) const noexcept;
	std::shared_ptr< Entity > getEntity( void ) noexcept;
	void setEntity( std::shared_ptr< Entity > value ) noexcept;
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;

	const TileSubtype* pSubtype;
	int8_t mHeight;
	std::shared_ptr< Entity > pEntity;
};

#endif
