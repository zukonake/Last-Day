#include "client.hpp"

void Client::render( void ) const
{
	camera->render( objectRenderer );
	return;
}

void Client::update( void ) noexcept
{
	sdl.update();
}

bool Client::handleEvents( void )
{
	const uint8_t* keystate = sdl.getKeystate();
	bool output = true;
	if(keystate[SDL_SCANCODE_LEFT])
    {
		camera->move( Direction::WEST );
    }
    if(keystate[SDL_SCANCODE_RIGHT])
    {
		camera->move( Direction::EAST );
    }
    if(keystate[SDL_SCANCODE_UP])
    {
		camera->move( Direction::NORTH );
    }
    if(keystate[SDL_SCANCODE_DOWN])
    {
		camera->move( Direction::SOUTH );
    }
	for( auto iterator : sdl.getEvents() )
	{
		if( iterator.type == SDL_QUIT )
		{
			output = false;
		}
		if( iterator.type == SDL_KEYDOWN ) //TODO remake dis
        {
            switch( iterator.key.keysym.sym )
            {
			case SDLK_ESCAPE:
				output = false;
		        break;
			case SDLK_e:
				camera->setZoom( camera->getZoom() - 1 );
			    break;
			case SDLK_q:
				camera->setZoom( camera->getZoom() + 1 );
				break;
			default:
				break;
            }
        }
	}
	SDL_Delay( 25 );
	return output;
}

void Client::connect( World& world ) noexcept
{
	if( !connected)
	{
		camera = new Camera( Point( 0, 0 ), world, sdl.getWindowSize() );
		connected = true;
	}
	return;
}

void Client::disconnect( void ) noexcept
{
	if( connected )
	{
		delete camera;
		connected = false;
	}
	return;
}

Client::Client( const Rectangle& windowSize, const std::string& windowTitle ) noexcept :
	sdl( windowSize, windowTitle ),
	objectRenderer( new ImageRenderer( sdl.getRenderer() ) ),
	camera( nullptr ),
	connected( false )
{

}

Client::~Client() noexcept
{
	delete objectRenderer;
	disconnect();
}
