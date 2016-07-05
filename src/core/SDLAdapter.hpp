#ifndef SDLADAPTER_HPP
#define SDLADAPTER_HPP

#include <cstdint>
#include <vector>
#include <string>
#include <SDL2/SDL.h>

struct Rectangle;

class SDLAdapter
{
public:
	SDLAdapter( const Rectangle& windowSize, const std::string& windowTitle );
	SDLAdapter( const SDLAdapter& that ) = delete;

	virtual ~SDLAdapter( void ) noexcept;

	SDLAdapter& operator=( const SDLAdapter& that ) = delete;

	SDL_Renderer* getRenderer( void ) const noexcept;
	std::vector< SDL_Event > getEvents( void ) const noexcept;
	const uint8_t* getKeystate( void ) const noexcept;
	Rectangle getWindowSize( void ) const noexcept;
	std::string getWindowTitle( void ) const noexcept;

	void update( void ) noexcept;
private:
	void initialize( void ) noexcept;
	void initializeWindow( const Rectangle& windowSize, const std::string& windowTitle );
	void initializeRenderer( void );
	void deinitializeSDL( void ) noexcept;

	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif
