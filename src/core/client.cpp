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
	camera( nullptr ),
	isConnected( false )
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
	camera->render( SFMLAdapter::getWindow() );
	return;
}

void Client::connect( World& world ) noexcept
{
	if( !isConnected)
	{
		camera = std::make_unique< Camera >( Point( 0, 0 ), world, SFMLAdapter::getWindowSize() );
		isConnected = true;
	}
	return;
}

void Client::disconnect( void ) noexcept
{
	if( isConnected )
	{
		camera.reset();
		isConnected = false;
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

bool Client::handleTime( void ) noexcept
{
	sf::Time waitingTime = sf::milliseconds( 25 );
	sf::Time elapsedTime = renderClock.getElapsedTime();
	if( elapsedTime >= waitingTime )
	{
		renderClock.restart();
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
		camera->move( Direction::WEST );
	}
	if( SFMLAdapter::isKeyPressed( sf::Keyboard::Right ) )
	{
		camera->move( Direction::EAST );
	}
	if( SFMLAdapter::isKeyPressed( sf::Keyboard::Up ) )
	{
		camera->move( Direction::NORTH );
	}
	if( SFMLAdapter::isKeyPressed( sf::Keyboard::Down ) )
	{
		camera->move( Direction::SOUTH );
	}
	return;
}


void Client::handleEvents( void ) noexcept
{
	for( auto iterator : SFMLAdapter::getEvents() )
	{
		if( iterator.type == sf::Event::Closed )
		{
			end();
		}
		if( iterator.type == sf::Event::KeyPressed ) //TODO remake dis
        {
            switch( iterator.key.code )
            {
			case sf::Keyboard::Escape:
				end();
		        break;
			case sf::Keyboard::E:
				camera->setZoom( camera->getZoom() / 2 );
			    break;
			case sf::Keyboard::Q:
				camera->setZoom( camera->getZoom() * 2 );
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
	if( !isConnected )
	{
		throw std::runtime_error( "Client::checkOperationViability, client is not connected." );
		return;
	}
	return;
}
