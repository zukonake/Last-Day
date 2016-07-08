#ifndef ENTITYCONTAINTER_HPP
#define ENTITYCONTAINTER_HPP

#include <memory>
#include <vector>
//
#include <nonCopyable.hpp>

struct Point;
class Entity;

class EntityContainer : NonCopyable
{
	typedef std::vector< std::shared_ptr< Entity > > tEntityVector;
public:
	EntityContainer( void ) noexcept { }

	virtual ~EntityContainer( void ) noexcept { }

	void simulate( void ) noexcept;

	std::shared_ptr< Entity > getEntity( const Point& targetPosition ) noexcept;
	void addEntity( std::shared_ptr< Entity > value );
private:
	tEntityVector mEntities;
};

#endif
