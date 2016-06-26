#include <iostream>
#include <exception>
//
#include <core/game.hpp>

int main( int argc, char* argv[] )
{
	int returnValue = 0;

	try
	{
		Game game;
		returnValue = game.start();
	}
	catch( std::exception& e )
	{
		std::cout << "ERROR: Standard exception: " << e.what() << ".\n";
		return 1;
	}

	return returnValue;
}
