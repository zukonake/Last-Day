#include "game.hpp"

int Game::start()
{
	isRunning = true;
	return loop();
}

int Game::loop()
{
	while( isRunning )
	{
		userInterfaceProxy.render();
		isRunning = userInterfaceProxy.handleEvents();
		//userInterfaceProxy.clear();
		worldProxy->simulate();
	}
	return end();
}

int Game::end()
{
	return 0;
}

Game::Game() :
	worldProxy( std::shared_ptr< WorldProxy > ( new WorldProxy() ) ),
	userInterfaceProxy( worldProxy )
{

}

Game::~Game()
{

}
