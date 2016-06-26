
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <geometry/point.hpp>
#include <world/world.hpp>
#include <entity/entity.hpp>
#include <entity/building/buildingSubtype.hpp>

class Building : public Entity< BuildingSubtype >
{
public:
	Building( BuildingSubtype* subtype, const Point& position, World& world );
	~Building();
};

#endif
