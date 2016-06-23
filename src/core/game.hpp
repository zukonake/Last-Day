#ifndef GAME_HPP
#define GAME_HPP

#include <geometry/point.hpp>
#include <data/worldProxy.hpp>
#include <render/userInterfaceProxy.hpp>

class Game
{
	WorldProxy worldProxy;
	UserInterfaceProxy userInterfaceProxy;
	bool isRunning;

	int loop();
public:
	int start();
	int end();

	Game();
	~Game();
};

#endif
