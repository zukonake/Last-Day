
#include <core/game.hpp>

int main( int argc, char* argv[] )
{
	int returnValue = 0;

	Game game;
	returnValue = game.start();

	return returnValue;
}
