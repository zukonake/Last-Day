#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cstdint>
#include <SFML/Graphics.hpp>
//
#include <geometry/rectangle.hpp>
#include <entity/entity.hpp>

struct Direction;
struct Point;
struct Rectangle;
class World;

class Camera : public Entity
{
public:
	Camera( const Point& position, World& world, const Rectangle& screenSize ) noexcept;

	void move( const Direction& targetDirection ) override;

	void resizeZoom( const bool& direction ) noexcept;
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
	void renderHeightEffects( const Point& targetTilePosition, sf::RenderTarget& target, sf::RenderStates states ) const noexcept;

	void updateViewRange( void ) noexcept;

	const Rectangle& mScreenSize;
	Rectangle mViewRange;
	uint8_t mZoom = 32;
};

#endif
