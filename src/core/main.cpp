#include <core/game.hpp>

int main( int argv, char* argc[] )
{
	Game* game = new Game();
	return game->start();
}
