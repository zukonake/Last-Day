#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cstdint>
//
#include <geometry/point.hpp>
#include <geometry/SDL_RectWrapper.hpp>
#include <geometry/rectangle.hpp>
#include <world/tileSubtype.hpp>
#include <entity/entity.hpp>
#include <world/world.hpp>

class Camera : public Entity
{
	Rectangle viewRange = Rectangle( 5, 3 );
	World& world;
public:
	void render( ObjectRenderer* renderer ) const;
	void updateViewRange( const Rectangle& screenSize, const uint8_t tileSize ) noexcept { viewRange = screenSize / tileSize; }

	Camera( const Point& position, World& world ) :
		Entity( nullptr, position ), world( world ) { }
	virtual ~Camera( void ) noexcept { };
};

#endif
