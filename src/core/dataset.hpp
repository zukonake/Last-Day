#ifndef DATSET_HPP
#define DATSET_HPP

#include <vector>
//
#include <entity/entity.hpp>
#include <entity/building.hpp>
#include <world/resource.hpp>
#include <world/world.hpp>

class Dataset
{
	std::vector< Building > initializedBuildings;
	std::vector< Entity > initializedEntities;
	std::vector< Resource > initializedResources;
	std::vector< World > initializedWorlds;
public:
	void initializeFromFiles();
	Dataset();
};

#endif
