#include "server.hpp"
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <SFML/System/Time.hpp>
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

void Server::connectClient( Client* target ) noexcept
{
	mConnectedClients.push_back( target );
	target->connect( *this );
	return;
}

void Server::disconnectClient( Client* target ) noexcept
{
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

Player* Server::createPlayer( const Point& position, const Point& screenSize ) noexcept
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
