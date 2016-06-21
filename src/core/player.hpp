#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <render/camera.hpp>
#include <entity/mob.hpp>

class Player : protected Mob
{
	Camera* camera;
public:
	Player();
	~Player();
};

#endif
