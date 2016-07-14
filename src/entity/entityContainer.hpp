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
	EntityContainer( void ) = default;

	virtual ~EntityContainer( void ) = default;

	void moveEntity( const Point& sourcePosition, const Point& targetPosition ) noexcept;
	void simulate( void ) noexcept;

	std::shared_ptr< Entity > getEntity( const Point& targetPosition ) noexcept;
	template < typename ObjectType, typename... Arguments >
	void addEntity( Arguments&&... arguments );
	void removeEntity( const Point& targetPosition ) noexcept;
private:
	tEntityMap mEntities;
};

template < typename ObjectType, typename... Arguments >
void EntityContainer::addEntity( Arguments&&... arguments )
{
	std::shared_ptr< ObjectType > value = std::make_shared< ObjectType > ( arguments... );
	mEntities[ value->getPosition() ] = value;
	return;
}

#endif
