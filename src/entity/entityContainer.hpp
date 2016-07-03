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
	EntityContainer( const EntityContainer& that ) = delete;

	virtual ~EntityContainer( void ) noexcept;

	EntityContainer& operator=( const EntityContainer& that ) = delete;

	void addEntity( Entity* value ) noexcept;
	void moveEntity( const Point& sourcePosition, const Point& targetPosition ) noexcept;
	Entity* getEntity( const Point& targetPosition ) noexcept;

	void simulate( void ) noexcept;
private:
	EntityMap2D entities;
};

#endif
