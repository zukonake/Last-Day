#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <SFML/System/Clock.hpp>
//
#include <core/SFMLAdapter.hpp>

struct Point;
class ObjectRenderer;
class World;
class Player;
class Server;

class Client : public SFMLAdapter
{
public:
	Client( void ) noexcept;

	~Client() noexcept;
	void connect( Server& server ) noexcept;
	void disconnect( void ) noexcept;

	void start( const Point& windowSize, const std::string& windowTitle ) noexcept;
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
