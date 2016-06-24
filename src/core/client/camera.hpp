#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cstdint>
#include <SDL/SDL.h>
//
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <world/world.hpp>

class Camera
{
	Point position;
	World& world;
	const uint8_t viewRange;
public:
	void render( SDL_Surface& targetSurface );

	void move( const Direction& direction );

	Camera( const Point& position, World& world, const uint8_t viewRange );
	~Camera();
};

#endif
