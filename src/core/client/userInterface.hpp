#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <string>
#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <render/image.hpp>

class UserInterface : public Image
{
	std::string name;
	Point screenPosition;
public:
	virtual void render( SDL_Renderer* targetRenderer );

	UserInterface();
	virtual ~UserInterface();
};

#endif
