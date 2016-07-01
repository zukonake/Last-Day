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

void SDLAdapter::initialize( void )
{
	SDL_Init( SDL_INIT_EVENTS | SDL_INIT_VIDEO );
	IMG_Init( IMG_INIT_PNG );
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
}

SDLAdapter::~SDLAdapter( void )
{
	deinitializeSDL();
}

void SDLAdapter::deinitializeSDL( void )
{
	IMG_Quit();
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
}
