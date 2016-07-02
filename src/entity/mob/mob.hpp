#ifndef MOB_HPP
#define MOB_HPP

#include <entity/entity.hpp>
#include <entity/mob/mobSubtype.hpp>

class World;

class Mob : public Entity
{
	void move();
public:
	Mob( MobSubtype* subtype, World& world, const Point& position );
	~Mob();
};

#endif
