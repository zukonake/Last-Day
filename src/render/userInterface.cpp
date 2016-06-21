#include "userInterface.hpp"

void UserInterface::render( SDL_Surface* targetSurface, SDL_Rect* targetPosition )
{

}

UserInterface::UserInterface()
{

}

UserInterface::~UserInterface()
{

}

UserInterface::operator SDL_Surface ()
{
	return *surface;
}
