#ifndef MOB_HPP
#define MOB_HPP

#include <entity/entity.hpp>
#include <entity/mob/mobSubtype.hpp>

class World;

class Mob : public Entity
{
public:
	Mob( World& world, const Point& position, const MobSubtype* subtype ) noexcept;
};

#endif
