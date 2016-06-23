#include "userInterface.hpp"

void UserInterface::render( SDL_Surface& targetSurface )
{
	SDL_BlitSurface( surface, NULL, &targetSurface, new SDL_RectWrapper( screenPosition ) );
}

UserInterface::UserInterface() : Image()
{

}

UserInterface::~UserInterface()
{

}

UserInterface::operator SDL_Surface ()
{
	return *surface;
}
