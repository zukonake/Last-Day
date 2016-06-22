#ifndef WORLDPROXY_HPP
#define WORLDPROXY_HPP

#include <data/dataset.hpp>
#include <world/world.hpp>
#include <entity/mob.hpp>
#include <entity/mobSubtype.hpp>
#include <entity/building.hpp>
#include <core/player.hpp>

class WorldProxy : protected World, protected Dataset
{
	std::vector< Mob > mobs;
	std::vector< Building > buildings;

	void initializeWorld();
public:
	void simulate();
	Player createPlayer( const Point2D& position );

	WorldProxy();
};

#endif
