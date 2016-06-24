#include "worldProxy.hpp"

void WorldProxy::simulate()
{

}

WorldProxy::WorldProxy() :
	Dataset(),
	World( dynamic_cast< Dataset& >( *this ) )
{
	
}
