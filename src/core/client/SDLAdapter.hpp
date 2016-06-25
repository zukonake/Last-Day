#ifndef SDLADAPTER_HPP
#define SDLADAPTER_HPP

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//
#include <geometry/direction.hpp>
#include <geometry/rectangle.hpp>

class SDLAdapter
{
protected:
	SDL_Event event;
	SDL_Window* window;
	SDL_Renderer* renderer;

	void initializeSDL();
	void initializeSDLWindow( const Rectangle& windowSize, const std::string& windowTitle );
	void initializeSDLRenderer();
	void deinitializeSDL();
public:
	void update();

	SDLAdapter();
	virtual ~SDLAdapter();
};

#endif
