#ifndef MOB_HPP
#define MOB_HPP

#include <entity/entity.hpp>

class Mob : protected Entity< MobSubtype >
{
	Mob();
	virtual ~Mob();
};

#endif
