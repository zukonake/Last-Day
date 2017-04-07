#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>
#include <SFML/System/Clock.hpp>
//
#include <nonCopyable.hpp>
#include <data/dataset.hpp>
#include <world/world.hpp>

class Client;
class Player;

class Server : NonCopyable
{
public:
	Server( void ) noexcept;

	~Server( void ) noexcept;

	void connectClient( Client* target ) noexcept;
	void disconnectClient( Client* target ) noexcept;

	void simulate( void ) noexcept;

	Player* createPlayer( const Point& position, const Point& windowSize ) noexcept;
private:
	bool handleTime( void ) noexcept;

	Dataset mDataset;
	World mWorld;

	std::vector< Client* > mConnectedClients;
	sf::Clock mSimulationClock;
};

#endif
