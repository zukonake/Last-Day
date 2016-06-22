
#include <core/game.hpp>

int main( int argv, char* argc[] )
{
	int returnValue = 0;

	Game* game = new Game();
	returnValue = game->start();
	delete game;
	
	return returnValue;
}
