#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <cstdint>
#include <iostream>
#include <exception>
#include <string>
#include <SDL2/SDL.h>
//
#include <geometry/rectangle.hpp>
#include <core/SDLAdapter.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <render/objectRenderer/imageRenderer.hpp>
#include <world/world.hpp>
#include <entity/camera.hpp>

class Client : public SDLAdapter
{
public:
	Client( const Rectangle& windowSize, const std::string& windowTitle ) noexcept;
	Client( const Client& that ) noexcept;
	~Client() noexcept;

	Client& operator=( const Client& that ) noexcept;

	void render( void ) const noexcept;

	void connect( World& world ) noexcept;
	void disconnect( void ) noexcept;

	void start( void ) noexcept;
	void end( void ) noexcept;

	const bool& getIsRunning( void ) const noexcept;

	void handleInput( void ) noexcept;
private:
	void handleKeyState( void ) noexcept;
	void handleEvents( void ) noexcept;

	void checkOperationViability( void ) const;

	ObjectRenderer* objectRenderer;
	Camera* camera;
	bool isConnected;
	bool isRunning;
};

#endif
