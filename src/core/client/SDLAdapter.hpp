#ifndef SDLADAPTER_HPP
#define SDLADAPTER_HPP

#include <string>
#include <SDL2/SDL.h>
//
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
	void initializeInterfaces();
	void deinitializeSDL();
public:
	void clear();

	SDLAdapter();
	~SDLAdapter();
};

#endif
