
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <entity/entity.hpp>

class Building : protected Entity< BuildingSubtype >
{
	Building();
	~Building();
};

#endif
