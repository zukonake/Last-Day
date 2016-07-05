#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
//
#include <core/SDLAdapter.hpp>

struct Rectangle;
class ObjectRenderer;
class World;
class Camera;

class Client : public SDLAdapter
{
public:
	Client( const Rectangle& windowSize, const std::string& windowTitle ) noexcept;
	Client( const Client& that ) = delete;
	~Client() noexcept;

	Client& operator=( const Client& that ) = delete;

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
