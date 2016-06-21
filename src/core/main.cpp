
#include <core/game.hpp>

int main( int argv, char* argc[] )
{
	Game* game = new Game();
	int returnValue = game->start();
	delete game;
	return returnValue;
}
