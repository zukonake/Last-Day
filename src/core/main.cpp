#include <core/game.hpp>

int main( int argv, char* argc[] )
{
	Game* game = new Game();
	game->start();
	game->end();
	return 0;
}
