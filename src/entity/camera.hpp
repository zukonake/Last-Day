#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cstdint>
//
#include <geometry/point.hpp>
#include <geometry/SDL_RectWrapper.hpp>
#include <geometry/rectangle.hpp>
#include <world/tileSubtype.hpp>
#include <world/world.hpp>
#include <entity/entity.hpp>
#include <core/entityProxy.hpp>

class Camera : public Entity
{
	Rectangle viewRange = Rectangle( 5, 3 );
public:
	void render( ObjectRenderer* renderer, EntityProxy* entityProxy ) const;
	void updateViewRange( const Rectangle& screenSize, const uint8_t tileSize ) noexcept { viewRange = screenSize / tileSize; }

	Camera( const Point& position, World& world ) :
		Entity( NULL, position, world ) { }
	virtual ~Camera( void ) noexcept { };
};

#endif
