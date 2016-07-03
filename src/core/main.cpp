#include <iostream>
#include <exception>
//
#include <geometry/rectangle.hpp>
#include <core/server.hpp>
#include <core/client.hpp>

int main( int argc, char* argv[] )
{
	int returnValue = 0;
	int tick = 0;

	Client client( Rectangle( 1280, 768 ), "Neue Spiele" );
	client.start();
	Server* server = new Server();
	server->connectClient( &client );
	try
	{
		while( client.getIsRunning() )
		{
			if( tick == 10 )
			{
				tick = 0;
				server->simulate();
			}
			client.render();
			client.handleInput();
			client.update();
			tick++;
		}
	}
	catch( std::exception& e )
	{
		std::cerr << "ERROR: Standard exception: " << e.what() << ".\n";
		returnValue = 1;
	}
	client.end();
	delete server;
	return returnValue;
}
