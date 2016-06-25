#ifndef WORLDPROXY_HPP
#define WORLDPROXY_HPP

#include <data/dataset.hpp>
#include <world/world.hpp>
#include <core/server/entityProxy.hpp>

class WorldProxy : protected Dataset, public World, public EntityProxy
{
public:
	void simulate();

	WorldProxy();
};

#endif
