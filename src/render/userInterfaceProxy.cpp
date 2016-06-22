#include "userInterfaceProxy.hpp"

void UserInterfaceProxy::render()
{
	for( auto iterator : userInterfaces )
	{
		iterator.second.render( surface );
	}
}

bool UserInterfaceProxy::handleEvents()
{
	while( SDL_PollEvent( &event ) )
	{
		if( event.type == SDL_QUIT )
		{
			return false;
		}
	}
	return true;
}

void UserInterfaceProxy::clear()
{

}

void UserInterfaceProxy::initializeWindow( const Rectangle& windowSize, const std::string& windowTitle )
{
	surface = SDL_SetVideoMode( windowSize.width, windowSize.height, 32, SDL_SWSURFACE );
	setWindowTitle( windowTitle );
}

void UserInterfaceProxy::setWindowTitle( const std::string& windowTitle )
{
	SDL_WM_SetCaption( windowTitle.c_str(), NULL );
}

void UserInterfaceProxy::initializeSDL()
{
	SDL_Init( SDL_INIT_EVERYTHING | SDL_DOUBLEBUF );
}

void UserInterfaceProxy::deinitializeSDL()
{
	SDL_Quit();
}

UserInterfaceProxy::UserInterfaceProxy( const Player& player ) :
	UserInterface(),
	player( player )
{
	initializeSDL();
	initializeWindow( Rectangle( 640, 480 ), "Neue spiele" );
}

UserInterfaceProxy::~UserInterfaceProxy()
{
	deinitializeSDL();
}
