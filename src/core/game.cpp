#include "game.hpp"

int Game::loop()
{
	while( isRunning )
	{
		SDL_Delay( 50 );
		userInterfaceProxy.render();
		isRunning = userInterfaceProxy.handleEvents();
		//userInterfaceProxy.clear();
		//worldProxy.simulate();
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
	worldProxy(),
	userInterfaceProxy( worldProxy.createPlayer( Point2D( 0, 0 ) ) )
{

}

Game::~Game()
{

}
