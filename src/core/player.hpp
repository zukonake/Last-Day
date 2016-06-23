#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL/SDL.h>
//
#include <render/userInterface.hpp>
#include <render/camera.hpp>
#include <entity/mobSubtype.hpp>
#include <entity/mob.hpp>

class Player : protected Mob
{
	Camera camera;
public:
	void render( SDL_Surface& targetSurface ) const;
	Point2D getPosition() const;

	Player( Point2D _position, World& world, const MobSubtype& subtype );
	~Player();
};

#endif
