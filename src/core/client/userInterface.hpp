#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <string>
#include <SDL/SDL.h>
//
#include <geometry/point.hpp>
#include <render/image.hpp>

class UserInterface : public Image
{
	std::string name;
	Point screenPosition;
public:
	virtual void render( SDL_Surface& targetSurface );

	UserInterface();
	virtual ~UserInterface();

	virtual operator SDL_Surface ();
};

#endif
