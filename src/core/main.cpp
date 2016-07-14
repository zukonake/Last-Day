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
	Client client( { 1280, 768  }, "Neue Spiele" );

	server->connectClient( &client );
	client.start();
	try
	{
		while( client.isRunning() )
		{
			client.loop();
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
