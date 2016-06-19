#include "game.hpp"

void Game::start()
{
	dataset.initializeVectorsFromFiles();
}

void Game::end()
{

}

Game::Game() : dataset( Dataset( fileHandler ))
{

}
