#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
//
#include <core/server/worldProxy.hpp>
#include <core/client/userInterfaceProxy.hpp>

class Game
{
	std::shared_ptr< WorldProxy > worldProxy;
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
