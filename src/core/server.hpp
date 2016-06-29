#ifndef SERVER_HPP
#define SERVER_HPP

#include <exception>
#include <vector>
#include <algorithm>
//
#include <data/dataset.hpp>
#include <world/world.hpp>
#include <core/entityProxy.hpp>
#include <core/client.hpp>

class Server
{
	std::vector< Client* > connectedClients;
	Dataset dataset;
	World world;
	EntityProxy entityProxy;
public:
	void connectClient( Client* target );
	void disconnectClient( Client* target );

	Server() noexcept;
	~Server();
};

#endif
