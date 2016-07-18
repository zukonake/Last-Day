#include <iostream>
#include <exception>
//

#include <core/server.hpp>
#include <core/client.hpp>

int main()
{
	int returnValue = 0;

	Server* server = new Server();
	Client client;

	client.start( { 1280, 768  }, "Neue Spiele" );
	server->connectClient( &client );
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
