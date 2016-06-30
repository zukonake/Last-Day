
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <entity/entity.hpp>
#include <entity/building/buildingSubtype.hpp>

class Building : public Entity
{
public:
	Building( BuildingSubtype* subtype, const Point& position );
	~Building();
};

#endif
