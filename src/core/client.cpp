#include "client.hpp"
#include <cstdint>
#include <exception>
#include <iostream>
//
#include <render/objectRenderer/imageRenderer.hpp>

Client::Client( const Rectangle& windowSize, const std::string& windowTitle ) noexcept :
	SDLAdapter( windowSize, windowTitle ),
	objectRenderer( new ImageRenderer( SDLAdapter::getRenderer() ) ),
	camera( nullptr ),
	isConnected( false ),
	isRunning( false )
{

}

Client::~Client() noexcept
{
	end();
	disconnect();
	delete objectRenderer;
}

void Client::render( void ) const noexcept
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
	camera->render( objectRenderer );
	return;
}

void Client::connect( World& world ) noexcept
{
	if( !isConnected)
	{
		camera = new Camera( Point( 0, 0 ), world, SDLAdapter::getWindowSize() );
		isConnected = true;
	}
	return;
}

void Client::disconnect( void ) noexcept
{
	if( isConnected )
	{
		delete camera;
		isConnected = false;
	}
	return;
}

void Client::start( void ) noexcept
{
	isRunning = true;
}

void Client::end( void ) noexcept
{
	isRunning = false;
}

const bool& Client::getIsRunning( void ) const noexcept
{
	return isRunning;
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
	SDL_Delay( 25 ); //Delay for slower camera movement
	const uint8_t* keyState = SDLAdapter::getKeystate();
	if( keyState[SDL_SCANCODE_LEFT] )
	{
		camera->move( Direction::WEST );
	}
	if( keyState[SDL_SCANCODE_RIGHT] )
	{
		camera->move( Direction::EAST );
	}
	if( keyState[SDL_SCANCODE_UP] )
	{
		camera->move( Direction::NORTH );
	}
	if( keyState[SDL_SCANCODE_DOWN] )
	{
		camera->move( Direction::SOUTH );
	}
	return;
}

void Client::handleEvents( void ) noexcept
{
	for( auto iterator : SDLAdapter::getEvents() )
	{
		if( iterator.type == SDL_QUIT )
		{
			end();
		}
		if( iterator.type == SDL_KEYDOWN ) //TODO remake dis
        {
            switch( iterator.key.keysym.sym )
            {
			case SDLK_ESCAPE:
				end();
		        break;
			case SDLK_e:
				camera->setZoom( camera->getZoom() / 2 );
			    break;
			case SDLK_q:
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
	if( !isRunning )
	{
		throw std::runtime_error( "Client::checkOperationViability, client is not running." );
		return;
	}
	if( !isConnected )
	{
		throw std::runtime_error( "Client::checkOperationViability, client is not connected." );
		return;
	}
}
