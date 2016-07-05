#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <memory>
#include <string>
#include <SFML/System.hpp>
//
#include <core/SFMLAdapter.hpp>

struct Rectangle;
class ObjectRenderer;
class World;
class Camera;

class Client : public SFMLAdapter
{
public:
	Client( const Rectangle& windowSize, const std::string& windowTitle ) noexcept;
	Client( const Client& that ) = delete;
	~Client() noexcept;

	Client& operator=( const Client& that ) = delete;

	void render( void ) noexcept;

	void connect( World& world ) noexcept;
	void disconnect( void ) noexcept;

	void start( void ) noexcept;
	void end( void ) noexcept;

	const bool isRunning( void ) const noexcept;

	void handleTime( void ) noexcept;
	void handleInput( void ) noexcept;
private:
	void handleKeyState( void ) noexcept;
	void handleEvents( void ) noexcept;

	void checkOperationViability( void ) const;

	std::unique_ptr< Camera > camera;
	sf::Clock clock;
	bool isConnected;
};

#endif
