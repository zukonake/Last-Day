#ifndef SERVER_HPP
#define SERVER_HPP

#include <core/client.hpp>
//
#include <map>
#include <string>

class Server
{
	typedef std::map< std::string*, Client* > clientMap;
	clientMap clients;
	bool isClientCorrect( Client* target );
	bool isClientIdConnected( std::string targetId );
public:
	void connectClient( Client* target );
	void disconnectClient( Client* target );
	void disconnectClientById( std::string targetId );
};

#endif
