
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <memory>
//
#include <entity/entity.hpp>
#include <entity/building/buildingSubtype.hpp>

class Building : public Entity< BuildingSubtype >
{
public:
	Building( const Point& position, World& world, std::shared_ptr < BuildingSubtype > subtype );
	~Building();
};

#endif
