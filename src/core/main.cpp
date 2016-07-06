#include <iostream>
#include <exception>
//
#include <geometry/rectangle.hpp>
#include <core/server.hpp>
#include <core/client.hpp>

int main()
{
	int returnValue = 0;

	Server* server = new Server();
	Client client( Rectangle( 1280, 768 ), "Neue Spiele" );

	client.start();
	server->connectClient( &client );
	try
	{
		while( client.isRunning() )
		{
			client.render();
			client.handleInput();
			client.update();
			client.handleTime();
			server->simulate();
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
