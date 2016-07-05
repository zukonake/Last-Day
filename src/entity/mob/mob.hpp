#ifndef MOB_HPP
#define MOB_HPP

#include <entity/entity.hpp>

struct Point;
class MobSubtype;
class World;

class Mob : public Entity
{
public:
	Mob( World& world, const Point& position, MobSubtype* subtype ) noexcept;

	void move( const Direction& targetDirection ) override;
};

#endif
