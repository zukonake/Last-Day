#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>
#include <SFML/System.hpp>
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

	void connectClient( Client* target );
	void disconnectClient( Client* target );

	void simulate( void ) noexcept;

	Player* createPlayer( const Point& position, const Rectangle& screenSize ) noexcept;
private:
	Dataset mDataset;
	World mWorld;

	std::vector< Client* > mConnectedClients;
	sf::Clock mSimulationClock;
};

#endif
