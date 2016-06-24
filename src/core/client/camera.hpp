#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cstdint>
#include <SDL2/SDL.h>
//
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <geometry/rectangle.hpp>
#include <world/tile.hpp>
#include <world/world.hpp>
#include <entity/entity.hpp>

class Camera : protected Entity< void >
{
	const Rectangle viewRange = Rectangle( 1280 / Tile::spriteSize, 768 / Tile::spriteSize ) ;
public:
	void render( SDL_Renderer* targetRenderer );

	void move( const Direction& direction );

	Camera( const Point& position, World& world );
	~Camera();
};

#endif
