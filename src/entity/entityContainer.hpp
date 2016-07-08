#ifndef ENTITYCONTAINTER_HPP
#define ENTITYCONTAINTER_HPP

#include <memory>
#include <map>
//
#include <nonCopyable.hpp>

struct Point;
class Entity;

class EntityContainer : NonCopyable
{
	typedef std::map< Point, std::shared_ptr< Entity > > tEntityMap;
public:
	EntityContainer( void ) noexcept { }

	virtual ~EntityContainer( void ) noexcept { }

	void moveEntity( const Point& sourcePosition, const Point& targetPosition ) noexcept;
	void simulate( void ) noexcept;

	std::shared_ptr< Entity > getEntity( const Point& targetPosition ) noexcept;
	void addEntity( std::shared_ptr< Entity > value );
	void removeEntity( const Point& targetPosition ) noexcept;
private:
	tEntityMap mEntities;
};

#endif
