#ifndef ENTITYAI_HPP
#define ENTITYAI_HPP

#include <cstdlib>
//
#include <geometry/direction.hpp>
#include <entity/entity.hpp>

class EntityAI
{
public:
	Entity& simulate( Entity& targetEntity ) const noexcept;
};

#endif
