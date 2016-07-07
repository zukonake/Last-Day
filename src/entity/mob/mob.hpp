#ifndef MOB_HPP
#define MOB_HPP

#include <entity/entity.hpp>

struct Point;
class MobSubtype;
class World;

class Mob : public Entity
{
public:
	Mob( const Point& position, const MobSubtype* subtype, World& world ) noexcept;

	void move( const Direction& targetDirection ) override;
};

#endif
