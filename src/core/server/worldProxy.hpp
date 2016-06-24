#ifndef WORLDPROXY_HPP
#define WORLDPROXY_HPP

#include <map>
//
#include <geometry/point.hpp>
#include <entity/mob/mob.hpp>
#include <entity/building/building.hpp>
#include <data/dataset.hpp>
#include <world/world.hpp>

class WorldProxy : protected Dataset, public World
{
	std::map< Point, Mob > mobs;
	std::map< Point, Building > buildings;
public:
	void simulate();

	WorldProxy();
};

#endif
