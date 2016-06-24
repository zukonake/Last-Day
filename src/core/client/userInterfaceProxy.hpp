#ifndef USERINTERFACEPROXY_HPP
#define USERINTERFACEPROXY_HPP

#include <memory>
#include <string>
#include <map>
#include <SDL/SDL.h>
//
#include <geometry/rectangle.hpp>
#include <core/server/worldProxy.hpp>
#include <core/client/userInterface.hpp>
#include <core/client/player.hpp>

class UserInterfaceProxy : public UserInterface
{
	std::map< const std::string, UserInterface > userInterfaces;
	std::shared_ptr< WorldProxy > worldProxy;
	SDL_Event event;
	Player player;
public:
	void render();
	bool handleEvents();
	void clear();
private:
	void initializeSDL();
	void initializeSDLWindow( const Rectangle& windowSize, const std::string& windowTitle );
	void setWindowTitle( const std::string& windowTitle );
	void initializeInterfaces();
	void deinitializeSDL();
public:
	UserInterfaceProxy( std::shared_ptr< WorldProxy > worldProxy );
	~UserInterfaceProxy();
};

#endif
