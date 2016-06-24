
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <entity/entity.hpp>
#include <entity/building/buildingSubtype.hpp>

class Building : public Entity< BuildingSubtype >
{
public:
	Building( const Point& position, World& world, const BuildingSubtype& subtype );
	~Building();
};

#endif
