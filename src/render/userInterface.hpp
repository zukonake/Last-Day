#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <string>
#include <SDL/SDL.h>
//
#include <render/sdl_rectWrapper.hpp>
#include <geometry/point.hpp>
#include <render/image.hpp>

class UserInterface : public Image
{
	std::string name;
	Point2D screenPosition;
	enum UserInterfaceType
	{
		screen,

	};
public:
	virtual void render( SDL_Surface& targetSurface );

	UserInterface();
	virtual ~UserInterface();

	virtual operator SDL_Surface ();
};

#endif
