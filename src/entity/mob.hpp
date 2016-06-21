#ifndef MOB_HPP
#define MOB_HPP

#include <geometry/direction.hpp>
#include <entity/entity.hpp>
#include <entity/mobSubtype.hpp>

class Mob : protected Entity< MobSubtype >, public Direction
{
	void move();
public:
	Mob();
	~Mob();
};

#endif
