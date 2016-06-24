#include "userInterfaceProxy.hpp"
#include <SDL/SDL_image.h>
//
#include <geometry/direction.hpp>

void UserInterfaceProxy::render()
{
	for( auto iterator = userInterfaces.begin(); iterator != userInterfaces.end(); iterator++ )
	{
		iterator->second.render( *surface );
	}
	player.render( *surface );
	SDL_Flip( surface );
}

bool UserInterfaceProxy::handleEvents()
{
	SDL_Delay( 50 );
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
			case SDLK_UP:
		        player.move( Direction::NORTH );
		        break;

            case SDLK_LEFT:
                player.move( Direction::WEST );
                break;

			case SDLK_DOWN:
	        	player.move( Direction::SOUTH );
	            break;

			case SDLK_RIGHT:
		        player.move( Direction::EAST );
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

UserInterfaceProxy::UserInterfaceProxy( std::shared_ptr< WorldProxy > worldProxy ) :
	UserInterface(),
	worldProxy( worldProxy ),
	player( Point( 0, 0 ), dynamic_cast< World& >( *worldProxy ) )
{
	initializeSDL();
	initializeSDLWindow( Rectangle( 800, 600 ), "Neue spiele" );
	initializeInterfaces();
}

void UserInterfaceProxy::initializeSDL()
{
	SDL_Init( SDL_INIT_EVERYTHING | SDL_DOUBLEBUF );
	IMG_Init( IMG_INIT_PNG );
}

void UserInterfaceProxy::initializeSDLWindow( const Rectangle& windowSize, const std::string& windowTitle )
{
	surface = SDL_SetVideoMode( windowSize.width, windowSize.height, 32, SDL_SWSURFACE );
	setWindowTitle( windowTitle );
}

void UserInterfaceProxy::setWindowTitle( const std::string& windowTitle )
{
	SDL_WM_SetCaption( windowTitle.c_str(), NULL );
}

void UserInterfaceProxy::initializeInterfaces()
{
	//userInterfaces[ "userInput" ]
}

UserInterfaceProxy::~UserInterfaceProxy()
{
	deinitializeSDL();
}

void UserInterfaceProxy::deinitializeSDL()
{
	SDL_Quit();
}
