#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>
#include <SFML/System.hpp>
//
#include <nonCopyable.hpp>
#include <data/dataset.hpp>
#include <world/world.hpp>

class Client;

class Server : NonCopyable
{
public:
	Server( void ) noexcept;

	~Server( void ) noexcept;

	void connectClient( Client* target );
	void disconnectClient( Client* target );

	void simulate( void ) noexcept;
private:
	std::vector< Client* > mConnectedClients;
	Dataset mDataset;
	World mWorld;
	sf::Clock mSimulationClock;
};

#endif
