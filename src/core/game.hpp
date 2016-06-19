#ifndef GAME_HPP
#define GAME_HPP

#include <core/fileHandler.hpp>
#include <core/dataset.hpp>
#include <core/player.hpp>

class Game
{
	FileHandler* fileHandler;
	Dataset dataset;
	Player* player;
	World* world;
public:
	void start();
	void end();
	Game();
};

#endif
