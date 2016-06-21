#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <string>
#include <SDL/SDL.h>
//
#include <render/image.hpp>

class UserInterface : public Image
{
	std::string name;
	enum UserInterfaceType
	{
		screen,

	};
public:
	virtual void render( SDL_Surface* targetSurface, SDL_Rect* targetPosition );

	UserInterface();
	virtual ~UserInterface();

	virtual operator SDL_Surface ();
};

#endif
