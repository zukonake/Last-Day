#ifndef MOB_HPP
#define MOB_HPP

#include <memory>
//
#include <world/world.hpp>
#include <entity/entity.hpp>
#include <entity/mob/mobSubtype.hpp>

class Mob : public Entity< MobSubtype >
{
	void move();
public:
	Mob( const Point& position, World& world, std::shared_ptr < MobSubtype > subtype );
	~Mob();
};

#endif
