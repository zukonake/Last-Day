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
class Player;
class Server;

class Client : public SFMLAdapter
{
public:
	Client( const Rectangle& windowSize, const std::string& windowTitle ) noexcept;

	~Client() noexcept;
	void connect( Server& server ) noexcept;
	void disconnect( void ) noexcept;

	void start( void ) noexcept;
	void end( void ) noexcept;

	void loop( void ) noexcept;

	bool isRunning( void ) const noexcept;
	bool isConnected( void ) const noexcept;
private:
	void render( void ) noexcept;

	bool handleTime( void ) noexcept;
	void handleInput( void ) noexcept;
	void handleKeyState( void ) noexcept;
	void handleEvents( void ) noexcept;

	bool isReady( void ) noexcept;

	Player* pPlayer;
	bool mIsConnected;
	sf::Clock mRenderClock;
};

#endif
