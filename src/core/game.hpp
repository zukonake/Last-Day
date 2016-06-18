#ifndef GAME_HPP
#define GAME_HPP

#include <core/dataset.hpp>
//
#include <core/player.hpp>

class Game
{
	Dataset dataset;
	Player* player;
public:
	void start();
	void end();
	Game();
};

#endif
