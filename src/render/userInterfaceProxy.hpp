#ifndef USERINTERFACEPROXY_HPP
#define USERINTERFACEPROXY_HPP

#include <string>
#include <map>
//
#include <geometry/rectangle.hpp>
#include <render/userInterface.hpp>
#include <core/player.hpp>

class UserInterfaceProxy : public UserInterface
{
	friend class Game;
	std::map< const std::string, UserInterface > userInterfaces;
	SDL_Event event;
	Player player;
public:
	void render();
	bool handleEvents();
	void clear();
private:
	void initializeSDL();
	void deinitializeSDL();
	void initializeWindow( const Rectangle& windowSize, const std::string& windowTitle );
	void setWindowTitle( const std::string& windowTitle );
public:
	UserInterfaceProxy( const Player& player );
	~UserInterfaceProxy();
};

#endif
