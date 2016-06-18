#ifndef GAME_HPP
#define GAME_HPP

#include <core/dataset.hpp>

class Game
{
	Dataset dataset;
public:
	void start();
	void end();
	Game();
};

#endif
