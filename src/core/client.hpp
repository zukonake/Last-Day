#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
//
#include <geometry/rectangle.hpp>
#include <core/SDLAdapter.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <render/objectRenderer/imageRenderer.hpp>
#include <world/tileSubtype.hpp>
#include <world/world.hpp>
#include <core/entityProxy.hpp>
#include <entity/camera.hpp>

class Client
{
	SDLAdapter sdl;
	ObjectRenderer* objectRenderer;
	EntityProxy* entityProxy;
	Camera* camera;
	bool connected;
public:
	void render( void ) const;
	void update( void ) noexcept;
	bool handleEvents( void );

	void connect( World& world, EntityProxy* _entityProxy );
	void disconnect( void ) noexcept;

	Client( const Rectangle& windowSize, const std::string& windowTitle ) noexcept;
	~Client() noexcept;
};

#endif
