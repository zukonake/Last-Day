#ifndef ENTITYPROXY_HPP
#define ENTITYPROXY_HPP

class EntityProxy
{
	std::map< const Point::coordinate, std::map< const Point::coordinate, Entity* entity > > entitesMap2D;
};

#endif
