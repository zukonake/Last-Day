#include "server.hpp"

bool Server::isClientCorrect( Client* target )
{
	if( target )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Server::isClientIdConnected( std::string targetId )
{
	if( isClientCorrect( clients[ &targetId ] ))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Server::connectClient( Client* target )
{
	if( !isClientIdConnected( target->id ))
	{
		clients[ &target->id ] = target;
		clients[ &target->id ]->connectToServer();
	}
	else
	{
		//TODO throw exception
	}
}

void Server::disconnectClient( Client* target )
{
	if( isClientIdConnected( target->id ))
	{
		clients[ &target->id ]->disconnectFromServer();
		clients.erase( &target->id );
	}
	else
	{
		//TODO throw exception
	}
}

void Server::disconnectClientById( std::string targetId )
{
	if( isClientIdConnected( targetId ))
	{
		clients[ &targetId ]->disconnectFromServer();
		clients.erase( &targetId );
	}
	else
	{
		//TODO throw exception
	}
}
