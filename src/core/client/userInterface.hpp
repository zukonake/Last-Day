#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <geometry/SDL_RectWrapper.hpp>
#include <render/image.hpp>

class UserInterface : public Image
{
	Point screenPosition;
public:
	virtual void render( SDL_Renderer* targetRenderer );

	UserInterface();
	virtual ~UserInterface();
};

#endif
