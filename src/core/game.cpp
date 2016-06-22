#include "game.hpp"

int Game::loop()
{
	while( isRunning )
	{
		userInterfaceProxy.render();
		isRunning = userInterfaceProxy.handleEvents();
		userInterfaceProxy.clear();
		worldProxy->simulate();
	}
	return end();
}

int Game::start()
{
	isRunning = true;
	return loop();
}

int Game::end()
{
	return 0;
}

Game::Game() :
	worldProxy( new WorldProxy() ),
	userInterfaceProxy( worldProxy->createPlayer( Point2D( 0, 0 ) ) )
{

}

Game::~Game()
{
	delete worldProxy;
}
