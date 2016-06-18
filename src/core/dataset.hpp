#ifndef DATSET_HPP
#define DATSET_HPP

#include <vector>
//
#include <entity/mobSubtype.hpp>
#include <entity/buildingSubtype.hpp>
#include <world/resourceSubtype.hpp>
#include <world/world.hpp>
#include <core/objectInitializer.hpp>

class Dataset
{
	std::vector< MobSubtype > initializedMobSubtypes;
	std::vector< BuildingSubtype > initializedBuildingSubtypes;
	std::vector< ResourceSubtype > initializedResourceSubtypes;
	World* mainWorld;
	ObjectInitializer initializer;
public:
	void initializeVectorsFromFiles();
	Dataset();
};

#endif
