#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cstdint>
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

	void render( ObjectRenderer* renderer ) const;
	void move( const Direction& targetDirection ) override;

	const uint8_t& getZoom( void ) const noexcept;
	void setZoom( const uint8_t& value ) noexcept;
private:
	void updateViewRange( void ) noexcept;

	Rectangle viewRange;
	Rectangle screenSize;
	uint8_t zoom = 32;
};

#endif
