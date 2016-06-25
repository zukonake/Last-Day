#ifndef ENTITYPROXY_HPP
#define ENTITYPROXY_HPP

#include <memory>
#include <vector>
#include <map>
//
#include <geometry/point.hpp>
#include <entity/entitySubtype.hpp>
#include <entity/entity.hpp>

class EntityProxy
{
	std::map< const Point::coordinate, std::map< const Point::coordinate , std::shared_ptr< Entity< EntitySubtype > > > > entities;
public:
	std::shared_ptr< Entity< EntitySubtype > > addEntity( std::shared_ptr< Entity< EntitySubtype > > entity );
	void removeEntity( const Point& targetPosition );

	std::shared_ptr< Entity< EntitySubtype > > getEntityOnTile( const Point& targetPosition );

	std::vector< std::shared_ptr< Entity< EntitySubtype > > > getVector();

	EntityProxy();
};

#endif
