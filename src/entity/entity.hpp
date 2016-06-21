#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <geometry/point.hpp>
#include <geometry/direction.hpp>
#include <world/world.hpp>

template < typename Subtype > class Entity
{
protected:
	Point2D position;
	World* world;
	Subtype* subtype;
public:
	virtual void render( UserInterface* targetUserInterface, SDL_Rect* targetPosition );
	virtual void teleport( const Point2D& targetPosition );

	Entity();
	virtual ~Entity();
};

template < typename Subtype >
void Entity< Subtype >::render( UserInterface* targetUserInterface, SDL_Rect* targetPosition )
{

}

template < typename Subtype >
void Entity< Subtype >::teleport( const Point2D& targetPosition )
{

}

template < typename Subtype >
Entity< Subtype >::Entity()
{

}

template < typename Subtype >
Entity< Subtype >::~Entity()
{

}


#endif
