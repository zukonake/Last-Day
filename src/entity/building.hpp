
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <entity/entity.hpp>

class Building : public Entity< BuildingSubtype >
{
public:
	Building();
	~Building();
};

#endif
