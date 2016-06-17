#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client
{
	friend class Server;
	std::string id;
	void connectToServer();
	void disconnectFromServer();
public:
	Client( std::string id ) : id(id) { }
};

#endif
