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
	Entity< EntitySubtype >* addEntity( Entity< EntitySubtype >* entity );
	Entity< EntitySubtype >* removeEntity( const Point& targetPosition );
	Entity< EntitySubtype >* getEntityOnTile( const Point& targetPosition );

	std::vector< std::shared_ptr< Entity< EntitySubtype > > > getVector();

	EntityProxy();
};

#endif
