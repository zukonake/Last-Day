#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstdint>
#include <SDL/SDL.h>
//
#include <geometry/point.hpp>
#include <geometry/rectangle.hpp>
#include <world/world.hpp>
#include <core/client/camera.hpp>

class Player : public Camera
{
public:
	void render( SDL_Surface& targetSurface );

	Player( const Point& position, World& world );
	~Player();
};

#endif
