#include "client.hpp"
#include <cstdint>
#include <exception>
#include <iostream>
//
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <entity/camera.hpp>

Client::Client( const Rectangle& windowSize, const std::string& windowTitle ) noexcept :
	SFMLAdapter( windowSize, windowTitle ),
	pCamera( nullptr ),
	mIsConnected( false )
{

}

Client::~Client() noexcept
{
	end();
	disconnect();
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
	SFMLAdapter::getWindow().draw( *pCamera );
	return;
}

void Client::connect( World& world ) noexcept
{
	if( !mIsConnected)
	{
		pCamera = std::make_unique< Camera >( Point( 0, 0 ), world, SFMLAdapter::getWindowSize() );
		mIsConnected = true;
	}
	return;
}

void Client::disconnect( void ) noexcept
{
	if( mIsConnected )
	{
		pCamera.reset();
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
		pCamera->move( Direction::WEST );
	}
	if( SFMLAdapter::isKeyPressed( sf::Keyboard::Right ) )
	{
		pCamera->move( Direction::EAST );
	}
	if( SFMLAdapter::isKeyPressed( sf::Keyboard::Up ) )
	{
		pCamera->move( Direction::NORTH );
	}
	if( SFMLAdapter::isKeyPressed( sf::Keyboard::Down ) )
	{
		pCamera->move( Direction::SOUTH );
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
				pCamera->setZoom( pCamera->getZoom() / 2 );
			    break;
			case sf::Keyboard::Q:
				pCamera->setZoom( pCamera->getZoom() * 2 );
				break;
			default:
				break;
            }
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
