#ifndef ENTITYCONTAINTER_HPP
#define ENTITYCONTAINTER_HPP

#include <map>
//
#include <geometry/point.hpp>

class Entity;

class EntityContainer
{
	typedef std::map< Point, Entity* > EntityMap2D;

	EntityMap2D entities;
public:
	void addEntity( Entity* value );
	void moveEntity( const Point& sourcePosition, const Point& targetPosition );
	Entity* getEntity( const Point& targetPosition );

	virtual ~EntityContainer( void );
};

#endif
