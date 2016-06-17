#include <core/server.hpp>
#include <core/client.hpp>

int main( int argv, char* argc[] )
{
	Server main = Server();
	Client* localClient = new Client( "TestClient" );
	main.connectClient( localClient );
	main.disconnectClient( localClient );
	return 0;
}
