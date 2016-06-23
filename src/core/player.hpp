#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SDL/SDL.h>
//
#include <render/userInterface.hpp>
#include <render/camera.hpp>
#include <entity/mobSubtype.hpp>
#include <entity/mob.hpp>

class Player : public Mob
{
	Camera camera;
public:
	void render( SDL_Surface& targetSurface );

	Player( Point2D _position, World& world, const MobSubtype& subtype );
	~Player();
};

#endif
