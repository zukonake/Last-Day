#include "SDLAdapter.hpp"

void SDLAdapter::update( void ) noexcept
{
	SDL_RenderPresent( renderer );
	SDL_RenderClear( renderer );
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

Rectangle SDLAdapter::getWindowSize( void ) const noexcept
{
	Rectangle output;
	SDL_GetWindowSize( window, ( int* )&output.width, ( int* )&output.height );
	return output;
}

SDLAdapter::SDLAdapter( const Rectangle& windowSize, const std::string& windowTitle )
{
	initializeSDL();
	initializeSDLWindow( windowSize, windowTitle );
	initializeSDLRenderer();
}

void SDLAdapter::initializeSDL( void )
{
	SDL_Init( SDL_INIT_EVENTS | SDL_INIT_VIDEO );
	IMG_Init( IMG_INIT_PNG );
}

void SDLAdapter::initializeSDLWindow( const Rectangle& windowSize, const std::string& windowTitle )
{
	window = SDL_CreateWindow( windowTitle.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		windowSize.width,
		windowSize.height,
		0 );
	if( !window )
	{
		std::cout << "ERROR: Couldn't initialize window.\n";
	}
}

void SDLAdapter::initializeSDLRenderer( void )
{
	renderer = SDL_CreateRenderer( window, -1, 0 );
	if( !renderer )
	{
		std::cout << "ERROR: Couldn't initialize renderer.\n";
	}
	SDL_SetRenderDrawBlendMode( renderer, SDL_BLENDMODE_BLEND );
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 63 );
	SDL_RenderClear( renderer );
	SDL_RenderSetLogicalSize( renderer, 1280, 768);
}

SDLAdapter::~SDLAdapter( void )
{
	deinitializeSDL();
}

void SDLAdapter::deinitializeSDL( void )
{
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
}
