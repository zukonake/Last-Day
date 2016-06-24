#include "SDLAdapter.hpp"

void SDLAdapter::update()
{
	SDL_RenderPresent( renderer );
}

SDLAdapter::SDLAdapter()
{
	initializeSDL();
	initializeSDLWindow( Rectangle( 1280, 768 ), "Neue spiele" );
	initializeSDLRenderer();
}

void SDLAdapter::initializeSDL()
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

void SDLAdapter::initializeSDLRenderer()
{
	renderer = SDL_CreateRenderer( window, -1, 0 );
	if( !renderer )
	{
		std::cout << "ERROR: Couldn't initialize renderer.\n";
	}
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
	SDL_RenderClear( renderer );
	SDL_RenderSetLogicalSize( renderer, 1280, 768);

}

SDLAdapter::~SDLAdapter()
{
	deinitializeSDL();
}

void SDLAdapter::deinitializeSDL()
{
	SDL_Quit();
}
