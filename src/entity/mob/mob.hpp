#ifndef MOB_HPP
#define MOB_HPP

#include <geometry/point.hpp>
#include <world/world.hpp>
#include <entity/entity.hpp>
#include <entity/mob/mobSubtype.hpp>

class Mob : public Entity< MobSubtype >
{
	void move();
public:
	Mob( MobSubtype* subtype, const Point& position, World& world );
	~Mob();
};

#endif
