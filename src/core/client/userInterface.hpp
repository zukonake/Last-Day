#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <geometry/SDL_RectWrapper.hpp>

class UserInterface
{
	Point screenPosition;
public:
	virtual void render( SDL_Renderer* targetRenderer );

	UserInterface();
	virtual ~UserInterface();
};

#endif
