#ifndef WORLDPROXY_HPP
#define WORLDPROXY_HPP

#include <data/dataset.hpp>
#include <world/world.hpp>
#include <world/worldGenerator.hpp>
#include <entity/mob.hpp>
#include <entity/building.hpp>

class WorldProxy : protected World, protected Dataset
{
	std::vector< Mob > mobs;
	std::vector< Building > buildings;
	WorldGenerator* generator;
public:
	void initializeWorld();

	WorldProxy();
};

#endif
