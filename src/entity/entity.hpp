#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <geometry/point.hpp>
#include <geometry/direction.hpp>
#include <world/world.hpp>

template < typename Subtype > class Entity
{
protected:
	World& world;
	const Subtype& subtype;
public:
	virtual void render( UserInterface* targetUserInterface, SDL_Rect& targetPosition );
	virtual void teleport( const Point2D& targetPosition );
	Point2D position; //TODO protected

	Entity( Point2D position, World& world, const Subtype& subtype );
	virtual ~Entity();
};

template < typename Subtype >
void Entity< Subtype >::render( UserInterface* targetUserInterface, SDL_Rect& targetPosition )
{

}

template < typename Subtype >
void Entity< Subtype >::teleport( const Point2D& targetPosition )
{
	position = targetPosition;
}

template < typename Subtype >
Entity< Subtype >::Entity( Point2D position, World& world, const Subtype& subtype ) :
	position( position ),
	world( world ),
	subtype( subtype )
{
	std::cout << "INFO: created entity: " << subtype.name << " " << position.x << " " << position.y << "\n";
}

template < typename Subtype >
Entity< Subtype >::~Entity()
{

}


#endif
