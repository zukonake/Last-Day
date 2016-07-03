#include "server.hpp"
#include <exception>
#include <algorithm>

Server::Server( void ) noexcept :
	dataset(),
	world( dataset )
{

}

Server::~Server( void ) noexcept
{
	for( auto iterator : connectedClients )
	{
		disconnectClient( iterator );
	}
}

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
	return;
}

void Server::simulate( void ) noexcept
{
	world.simulate();
	return;
}
