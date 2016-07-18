#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cstdint>
#include <SFML/Graphics.hpp>
//

#include <entity/entity.hpp>

struct Direction;
struct Point;
class World;

class Camera : public Entity
{
public:
	Camera( const Point& position, World& world, Point screenSize ) noexcept;

	void move( const Direction& targetDirection ) override;
	Point getPositionMouseIsOn( const Point& mousePosition ) const noexcept;

	void resizeZoom( const bool& direction ) noexcept;
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;
	void renderHeightEffects( const Point& targetTilePosition, sf::RenderTarget& target, sf::RenderStates states ) const noexcept;
	void renderTimeEffects( sf::RenderTarget& target, sf::RenderStates states ) const noexcept;

	void updateViewRange( void ) noexcept;

	Point mScreenSize;
	Point mViewRange;
	uint8_t mZoom = 32;
};

#endif
