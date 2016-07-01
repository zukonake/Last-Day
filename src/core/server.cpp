#include "server.hpp"

void Server::connectClient( Client* target )
{
	if( target == nullptr )
	{
		throw std::invalid_argument( "Server::disconnectClient, null pointer given in argument 1." );
		return;
	}
	connectedClients.push_back( target );
	target->connect( world );
	return;
}

void Server::disconnectClient( Client* target )
{
	if( target == nullptr )
	{
		throw std::invalid_argument( "Server::disconnectClient, null pointer given in argument 1." );
		return;
	}
	auto iterator = std::find( connectedClients.begin(), connectedClients.end(), target);
	connectedClients[ std::distance( connectedClients.begin(), iterator ) ]->disconnect();
	connectedClients.erase( iterator );
}

void Server::simulate( void )
{
	world.simulate();
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
