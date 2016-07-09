#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <memory>
#include <string>
#include <SFML/System.hpp>
//
#include <nonCopyable.hpp>
#include <core/SFMLAdapter.hpp>

struct Rectangle;
class ObjectRenderer;
class World;
class Camera;
class Server;

class Client : public SFMLAdapter, NonCopyable
{
public:
	Client( const Rectangle& windowSize, const std::string& windowTitle ) noexcept;

	~Client() noexcept;

	void render( void ) noexcept;

	void connect( Server& server ) noexcept;
	void disconnect( void ) noexcept;

	void start( void ) noexcept;
	void end( void ) noexcept;

	bool isRunning( void ) const noexcept;
	bool isConnected( void ) const noexcept;

	bool handleTime( void ) noexcept;
	void handleInput( void ) noexcept;
private:
	void handleKeyState( void ) noexcept;
	void handleEvents( void ) noexcept;

	void checkOperationViability( void ) const;

	Camera* pCamera;
	sf::Clock mRenderClock;
	bool mIsConnected;
};

#endif
