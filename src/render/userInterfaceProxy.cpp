#include "userInterfaceProxy.hpp"
#include <SDL/SDL_image.h>

void UserInterfaceProxy::render()
{
	for( auto iterator : userInterfaces )
	{
		iterator.second.render( *surface );
	}
	player.render( *surface );
	SDL_Flip( surface );
}

bool UserInterfaceProxy::handleEvents()
{
	while( SDL_PollEvent( &event ) )
	{
		if( event.type == SDL_QUIT )
		{
			return false;
		}
		if( event.type == SDL_KEYDOWN ) //TODO remake dis
        {
            switch( event.key.keysym.sym )
            {
            case SDLK_RIGHT:
                player.position.x++;
                break;

			case SDLK_LEFT:
	        	player.position.x--;
	            break;

			case SDLK_UP:
	            player.position.y--;
	            break;

			case SDLK_DOWN:
		        player.position.y++;
		        break;

			default:
				break;
            }
        }
	}
	return true;
}

void UserInterfaceProxy::clear()
{

}

void UserInterfaceProxy::initializeInterfaces()
{
	//userInterfaces[ "userInput" ]
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
	IMG_Init( IMG_INIT_PNG );
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
	initializeWindow( Rectangle( 800, 600 ), "Neue spiele" );
}

UserInterfaceProxy::~UserInterfaceProxy()
{
	deinitializeSDL();
}
