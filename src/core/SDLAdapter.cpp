#include "SDLAdapter.hpp"
#include <exception>
#include <iostream>
#include <SDL2/SDL_image.h>
//
#include <geometry/rectangle.hpp>

SDLAdapter::SDLAdapter( const Rectangle& windowSize, const std::string& windowTitle )
{
	try
	{
		initialize();
		initializeWindow( windowSize, windowTitle );
		initializeRenderer();
	}
	catch( std::exception& e )
	{
		std::cerr << "ERROR: Standard exception: " << e.what() << "\n";
		return;
	}
}

SDLAdapter::~SDLAdapter( void ) noexcept
{
	deinitializeSDL();
}

void SDLAdapter::update( void ) noexcept
{
	SDL_RenderPresent( renderer );
	SDL_RenderClear( renderer );
	return;
}

SDL_Renderer* SDLAdapter::getRenderer( void ) const noexcept
{
	return renderer;
}

std::vector< SDL_Event > SDLAdapter::getEvents( void ) const noexcept
{
	SDL_Event event;
	std::vector< SDL_Event > output;
	while( SDL_PollEvent( &event ) )
	{
		output.push_back( event );
	}
	return output;
}

const uint8_t* SDLAdapter::getKeystate( void ) const noexcept
{
	return SDL_GetKeyboardState( nullptr );
}

Rectangle SDLAdapter::getWindowSize( void ) const noexcept
{
	Rectangle output;
	SDL_GetWindowSize( window, ( int* )&output.width, ( int* )&output.height );
	return output;
}

std::string SDLAdapter::getWindowTitle( void ) const noexcept
{
	return SDL_GetWindowTitle( window );
}

void SDLAdapter::initialize( void ) noexcept
{
	SDL_Init( SDL_INIT_EVENTS | SDL_INIT_VIDEO );
	IMG_Init( IMG_INIT_PNG );
	return;
}

void SDLAdapter::initializeWindow( const Rectangle& windowSize, const std::string& windowTitle )
{
	window = SDL_CreateWindow( windowTitle.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		windowSize.width,
		windowSize.height,
		0 );
	if( !window )
	{
		throw std::runtime_error( "SDLAdapter::initializeWindow, couldn't initialize window." );
		return;
	}
	return;
}

void SDLAdapter::initializeRenderer( void )
{
	renderer = SDL_CreateRenderer( window, -1, 0 );
	if( !renderer )
	{
		throw std::runtime_error( "SDLAdapter::initializeRenderer, couldn't initialize renderer." );
		return;
	}
	SDL_SetRenderDrawBlendMode( renderer, SDL_BLENDMODE_BLEND );
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 63 );
	SDL_RenderClear( renderer );
	SDL_RenderSetLogicalSize( renderer, 1280, 768);
	return;
}

void SDLAdapter::deinitializeSDL( void ) noexcept
{
	IMG_Quit();
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
	return;
}
