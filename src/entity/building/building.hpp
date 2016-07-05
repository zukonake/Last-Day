
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <entity/entity.hpp>

struct Point;
class BuildingSubtype;
class World;

class Building : public Entity
{
public:
	Building( World& world, const Point& position, const BuildingSubtype* subtype ) noexcept;
};

#endif
