#include "server.hpp"

void Server::connectClient( Client* target )
{
	if( target == NULL )
	{
		throw std::invalid_argument( "ERROR: Server::disconnectClient, null pointer given in argument 1." );
		return;
	}
	connectedClients.push_back( target );
	target->connect( world, &entityProxy );
	return;
}

void Server::disconnectClient( Client* target )
{
	if( target == NULL )
	{
		throw std::invalid_argument( "ERROR: Server::disconnectClient, null pointer given in argument 1." );
		return;
	}
	auto iterator = std::find( connectedClients.begin(), connectedClients.end(), target);
	connectedClients[ std::distance( connectedClients.begin(), iterator ) ]->disconnect();
	connectedClients.erase( iterator );
}

Server::Server() noexcept :
	dataset(),
	world( dataset )
{

}

Server::~Server()
{
	for( auto iterator : connectedClients )
	{
		disconnectClient( iterator );
	}
}
