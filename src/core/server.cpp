#include "server.hpp"
#include <exception>
#include <cstdlib>
#include <algorithm>
#include <ctime>
//
#include <core/client.hpp>

Server::Server( void ) noexcept :
	mDataset(),
	mWorld( mDataset, ( int ) time( nullptr ) )
{
	srand( time( nullptr ) );
}

Server::~Server( void ) noexcept
{
	for( auto iClient : mConnectedClients )
	{
		disconnectClient( iClient );
	}
}

void Server::connectClient( Client* target )
{
	if( target == nullptr )
	{
		throw std::invalid_argument( "Server::disconnectClient, null pointer given in argument 1." );
		return;
	}
	mConnectedClients.push_back( target );
	target->connect( *this );
	return;
}

void Server::disconnectClient( Client* target )
{
	if( target == nullptr )
	{
		throw std::invalid_argument( "Server::disconnectClient, null pointer given in argument 1." );
		return;
	}
	auto iClient = std::find( mConnectedClients.begin(), mConnectedClients.end(), target);
	mConnectedClients[ std::distance( mConnectedClients.begin(), iClient ) ]->disconnect();
	mConnectedClients.erase( iClient );
	return;
}

void Server::simulate( void ) noexcept
{
	if( handleTime() )
	{
		mWorld.simulate();
	}
	return;
}

Player* Server::createPlayer( const Point& position, const Rectangle& screenSize ) noexcept
{
	return mWorld.createPlayer( position, screenSize );
}

bool Server::handleTime( void ) noexcept
{
	sf::Time waitingTime = sf::milliseconds( 150 );
	sf::Time elapsedTime = mSimulationClock.getElapsedTime();
	if( elapsedTime >= waitingTime )
	{
		mSimulationClock.restart();
		return true;
	}
	return false;
}
