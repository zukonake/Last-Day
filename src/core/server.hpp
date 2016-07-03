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
	Server( const Server& that ) = delete;

	~Server( void ) noexcept;

	Server& operator=( const Server& that ) = delete;

	void connectClient( Client* target );
	void disconnectClient( Client* target );

	void simulate( void ) noexcept;
private:
	std::vector< Client* > connectedClients;
	Dataset dataset;
	World world;
};

#endif
