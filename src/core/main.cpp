#include <iostream>
#include <exception>
//
#include <geometry/rectangle.hpp>
#include <core/server.hpp>
#include <core/client.hpp>

int main( int argc, char* argv[] )
{
	int returnValue = 0;
	bool isRunning = true;

	Client client( Rectangle( 1280, 768 ), "Neue Spiele" );
	Server* server = new Server();
	server->connectClient( &client );
	int tick = 0;
	try
	{
		while( isRunning )
		{
			tick++;
			client.render();
			isRunning = client.handleEvents();
			client.update();
			if( tick == 10 )
			{
				server->simulate();
				tick = 0;
			}
		}
	}
	catch( std::exception& e )
	{
		std::cerr << "ERROR: Standard exception: " << e.what() << ".\n";
		returnValue = 1;
	}
	delete server;
	return returnValue;
}
