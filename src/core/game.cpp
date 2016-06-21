#include "game.hpp"

int Game::loop()
{
	while( isRunning )
	{

	}
	return end();
}

int Game::start()
{
	return loop();
}

int Game::end()
{
	return 0;
}

Game::Game() : worldProxy( new WorldProxy() )
{

}

Game::~Game()
{
	delete worldProxy;
}
