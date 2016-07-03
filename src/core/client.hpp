#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
//
#include <geometry/rectangle.hpp>
#include <core/SDLAdapter.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <render/objectRenderer/imageRenderer.hpp>
#include <world/tile/tileSubtype.hpp>
#include <world/world.hpp>
#include <entity/camera.hpp>

class Client : public SDLAdapter
{
	ObjectRenderer* objectRenderer;
	Camera* camera;
	bool connected;
public:
	void render( void ) const;
	bool handleEvents( void );

	void connect( World& world ) noexcept;
	void disconnect( void ) noexcept;

	Client( const Rectangle& windowSize, const std::string& windowTitle ) noexcept;
	~Client() noexcept;
};

#endif
