#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <render/userInterface.hpp>
#include <render/camera.hpp>
#include <entity/mobSubtype.hpp>
#include <entity/mob.hpp>

class Player : protected Mob
{
	Camera camera;
public:
	void render( UserInterface* targetUserInterface );

	Player( const Point2D& position, World& world, const MobSubtype& subtype );
	~Player();
};

#endif
