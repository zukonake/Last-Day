#ifndef USERINTERFACEPROXY_HPP
#define USERINTERFACEPROXY_HPP

#include <memory>
#include <string>
#include <map>
#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <world/tileSubtype.hpp>
#include <core/server/worldProxy.hpp>
#include <core/client/userInterface.hpp>
#include <core/client/player.hpp>
#include <core/client/SDLAdapter.hpp>
#include <render/objectRenderer/imageRenderer.hpp>

class UserInterfaceProxy : public SDLAdapter
{
	std::map< const std::string, UserInterface > userInterfaces;
	std::shared_ptr< WorldProxy > worldProxy;
	std::shared_ptr< ObjectRenderer > objectRenderer;
	Player player;
public:
	void render();
	bool handleEvents();

	UserInterfaceProxy( std::shared_ptr< WorldProxy > worldProxy );
	~UserInterfaceProxy() { };
};

#endif
