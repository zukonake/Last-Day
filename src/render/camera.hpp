#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SDL/SDL.h>
//
#include <geometry/point.hpp>
#include <render/sdl_rectWrapper.hpp>
#include <world/world.hpp>
#include <render/userInterface.hpp>

class Camera
{
	Point2D position;
public:
	World& world;
	int viewRange;

	void render( SDL_Surface& targetSurface, SDL_Rect& targetPosition ) const;

	Camera( Point2D position, World& world, const unsigned int& viewRange );
	~Camera();
};

#endif
