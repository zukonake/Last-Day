#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>
//
#include <data/dataset.hpp>
#include <world/world.hpp>
#include <core/client.hpp>

class Server
{
public:
	Server( void ) noexcept;
	~Server( void ) noexcept;

	void connectClient( Client* target );
	void disconnectClient( Client* target );

	void simulate( void ) noexcept;
private:
	std::vector< Client* > connectedClients;
	Dataset dataset;
	World world;
};

#endif
