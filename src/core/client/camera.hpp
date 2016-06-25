#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <geometry/SDL_RectWrapper.hpp>
#include <geometry/rectangle.hpp>
#include <world/tileSubtype.hpp>
#include <world/world.hpp>
#include <entity/entity.hpp>

class Camera : public Entity< void >
{
	Rectangle viewRange;
public:
	void render( SDL_Renderer* targetRenderer );

	Camera( const Point& position, World& world );
	~Camera();
};

#endif
