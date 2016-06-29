#ifndef ENTITYPROXY_HPP
#define ENTITYPROXY_HPP

#include <exception>
#include <vector>
//
#include <geometry/point.hpp>
#include <entity/entity.hpp>

class EntityProxy
{
	typedef std::vector< Entity* > entityVector;

	entityVector entities;
public:
	void addEntity( Entity* target );
	void removeEntity( Entity* target );
	Entity* findEntity( const Point& targetPosition ) const;

	EntityProxy( void ) noexcept { }
	virtual ~EntityProxy( void ) noexcept;
};

#endif
