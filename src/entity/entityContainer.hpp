#ifndef ENTITYCONTAINTER_HPP
#define ENTITYCONTAINTER_HPP

#include <map>
//
#include <geometry/point.hpp>

class Entity;

class EntityContainer
{
	typedef std::map< Point, Entity* > EntityMap2D;
public:
	virtual ~EntityContainer( void ) noexcept;

	void addEntity( Entity* value ) noexcept;
	void moveEntity( const Point& sourcePosition, const Point& targetPosition ) noexcept;
	Entity* getEntity( const Point& targetPosition ) noexcept;

	void simulate( void ) noexcept;
private:
	EntityMap2D entities;
};

#endif
