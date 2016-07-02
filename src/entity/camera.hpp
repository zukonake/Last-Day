#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cstdint>
//
#include <geometry/point.hpp>
#include <geometry/SDL_RectWrapper.hpp>
#include <geometry/rectangle.hpp>
#include <world/tileSubtype.hpp>
#include <entity/entity.hpp>

class World;

class Camera : public Entity
{
	Rectangle viewRange = Rectangle( 5, 3 );
	Rectangle screenSize;
	uint8_t zoom = 32;
public:
	void render( ObjectRenderer* renderer ) const;

	void updateViewRange( void ) noexcept { viewRange = screenSize / zoom; }

	uint8_t& getZoom( void ) noexcept { return zoom; }
	void setZoom( const uint8_t& value ) noexcept;

	Camera( const Point& position, World& world, const Rectangle& screenSize ) noexcept;
	virtual ~Camera( void ) noexcept { };
};

#endif
