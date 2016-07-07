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

	World& getWorld( void ) noexcept;
	const Dataset& getDataset( void ) const noexcept;
private:
	Dataset mDataset;
	World mWorld;

	std::vector< Client* > mConnectedClients;
	sf::Clock mSimulationClock;
};

#endif
