#ifndef MOB_HPP
#define MOB_HPP

#include <geometry/direction.hpp>
#include <entity/entity.hpp>
#include <entity/mobSubtype.hpp>

class Mob : public Entity< MobSubtype >, public Direction
{
	void move();
public:
	Mob( Point2D position, World& world, const MobSubtype& subtype );
	~Mob();
};

#endif
