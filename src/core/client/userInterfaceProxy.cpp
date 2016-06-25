#include "userInterfaceProxy.hpp"

void UserInterfaceProxy::render()
{
	for( auto iterator = userInterfaces.begin(); iterator != userInterfaces.end(); iterator++ )
	{
		iterator->second.render( renderer );
	}
	player.render( renderer );
}

bool UserInterfaceProxy::handleEvents()
{
	const uint8_t* keystate = SDL_GetKeyboardState(NULL);
	bool output = true;
	if(keystate[SDL_SCANCODE_LEFT])
    {
		player.move( Direction::WEST );
    }
    if(keystate[SDL_SCANCODE_RIGHT])
    {
		player.move( Direction::EAST );
    }
    if(keystate[SDL_SCANCODE_UP])
    {
		player.move( Direction::NORTH );
    }
    if(keystate[SDL_SCANCODE_DOWN])
    {
		player.move( Direction::SOUTH );
    }
	while( SDL_PollEvent( &event ) )
	{
		if( event.type == SDL_QUIT )
		{
			output = false;
		}
		if( event.type == SDL_KEYDOWN ) //TODO remake dis
        {
            switch( event.key.keysym.sym )
            {
			case SDL_SCANCODE_ESCAPE:
				output = false;
		        break;
			default:
				break;
            }
        }
	}
	SDL_Delay( 25 );
	return output;
}

UserInterfaceProxy::UserInterfaceProxy( std::shared_ptr< WorldProxy > worldProxy ) :
	worldProxy( worldProxy ),
	player( Point( 0, 0 ), dynamic_cast< World& >( *worldProxy ) )
{
	
}
