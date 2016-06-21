#ifndef GAME_HPP
#define GAME_HPP

#include <data/worldProxy.hpp>
#include <core/player.hpp>

class Game
{

	Player player;
	WorldProxy* worldProxy;
	bool isRunning;

	int loop();
public:
	int start();
	int end();

	Game();
	~Game();
};

#endif
