#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>
#include <SDL/SDL.h>
//
#include <render/image.hpp>

class Interface : public Image
{
	std::string name;
public:
	Interface();
	~Interface();

	virtual operator SDL_Surface ();
};

#endif
