#ifndef MOB_HPP
#define MOB_HPP

#include <memory>
#include <entity/entity.hpp>

struct Point;
class MobSubtype;
class World;

class Mob : public Entity
{
public:
	Mob( const Point& position, const MobSubtype* subtype, World& world ) noexcept;
	Mob( void ) = default;

	void move( const Direction& targetDirection ) override;
};

#endif
