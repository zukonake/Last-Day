#include <iostream>
#include <exception>
//
#include <core/server.hpp>
#include <core/client.hpp>

int main( int argc, char* argv[] )
{
	int returnValue = 0;
	bool isRunning = true;

	Client client( Rectangle( 1280, 768 ), "Neue Spiele" );
	Server* server = new Server();
	server->connectClient( &client );
	try
	{
		while( isRunning )
		{
			client.render();
			isRunning = client.handleEvents();
			client.update();
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
