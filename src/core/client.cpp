#include "client.hpp"
#include <cstdint>
#include <exception>
#include <iostream>
//
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <core/player.hpp>
#include <core/server.hpp>

Client::Client( const Rectangle& windowSize, const std::string& windowTitle ) noexcept :
	SFMLAdapter( windowSize, windowTitle ),
	pPlayer( nullptr ),
	mIsConnected( false )
{

}

Client::~Client() noexcept
{
	end();
	disconnect();
}

void Client::connect( Server& server ) noexcept
{
	if( !mIsConnected)
	{
		pPlayer = server.createPlayer( Point( 0, 0 ), SFMLAdapter::getWindowSize() );
		mIsConnected = true;
	}
	return;
}

void Client::disconnect( void ) noexcept
{
	if( mIsConnected )
	{
		delete pPlayer;
		mIsConnected = false;
	}
	return;
}

void Client::start( void ) noexcept
{
	SFMLAdapter::initialize();
	return;
}

void Client::end( void ) noexcept
{
	SFMLAdapter::deinitialize();
	return;
}

void Client::render( void ) noexcept
{
	try
	{
		checkOperationViability();
	}
	catch( std::exception& e )
	{
		std::cerr << "ERROR: Standard exception: " << e.what() << ".\n";
		return;
	}
	SFMLAdapter::getWindow().draw( *pPlayer );
	return;
}

bool Client::isRunning( void ) const noexcept
{
	return SFMLAdapter::isRunning();
}

bool Client::isConnected( void ) const noexcept
{
	return mIsConnected;
}

bool Client::handleTime( void ) noexcept
{
	sf::Time waitingTime = sf::milliseconds( 25 );
	sf::Time elapsedTime = mRenderClock.getElapsedTime();
	if( elapsedTime >= waitingTime )
	{
		mRenderClock.restart();
		return true;
	}
	return false;
}

void Client::handleInput( void ) noexcept
{
	try
	{
		checkOperationViability();
	}
	catch( std::exception& e )
	{
		std::cerr << "ERROR: Standard exception: " << e.what() << ".\n";
		return;
	}
	handleKeyState();
	handleEvents();
	return;
}

void Client::handleKeyState( void ) noexcept
{
	if( SFMLAdapter::isKeyPressed( sf::Keyboard::Left ) )
	{
		pPlayer->move( Direction::WEST );
	}
	if( SFMLAdapter::isKeyPressed( sf::Keyboard::Right ) )
	{
		pPlayer->move( Direction::EAST );
	}
	if( SFMLAdapter::isKeyPressed( sf::Keyboard::Up ) )
	{
		pPlayer->move( Direction::NORTH );
	}
	if( SFMLAdapter::isKeyPressed( sf::Keyboard::Down ) )
	{
		pPlayer->move( Direction::SOUTH );
	}
	return;
}


void Client::handleEvents( void ) noexcept
{
	for( auto iEvent : SFMLAdapter::getEvents() )
	{
		if( iEvent.type == sf::Event::Closed )
		{
			end();
		}
		if( iEvent.type == sf::Event::KeyPressed ) //TODO remake dis
        {
            switch( iEvent.key.code )
            {
			case sf::Keyboard::Escape:
				end();
		        break;
			case sf::Keyboard::E:
				pPlayer->resizeZoom( 0 );
			    break;
			case sf::Keyboard::Q:
				pPlayer->resizeZoom( 1 );
				break;
			default:
				break;
            }
        }
		if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
		{

		}
	}
	return;
}

void Client::checkOperationViability( void ) const
{
	if( !isRunning() )
	{
		throw std::runtime_error( "Client::checkOperationViability, client is not running." );
		return;
	}
	if( !mIsConnected )
	{
		throw std::runtime_error( "Client::checkOperationViability, client is not connected." );
		return;
	}
	return;
}
