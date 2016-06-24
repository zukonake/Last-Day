#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <SDL/SDL.h>
//
#include <geometry/point.hpp>
#include <geometry/direction.hpp>
#include <world/world.hpp>

template < typename Subtype > class Entity
{
protected:
	Point position;
	World& world;
	const Subtype& subtype;
public:
	virtual void render( SDL_Surface& targetUserInterface, SDL_Rect& targetPosition );
	virtual void teleport( const Point& targetPosition );

	Entity( const Point& position, World& world, const Subtype& subtype );
	virtual ~Entity();
};

template < typename Subtype >
void Entity< Subtype >::render( SDL_Surface& targetUserInterface, SDL_Rect& targetPosition )
{

}

template < typename Subtype >
void Entity< Subtype >::teleport( const Point& targetPosition )
{
	position = targetPosition;
}

template < typename Subtype >
Entity< Subtype >::Entity( const Point& position, World& world, const Subtype& subtype ) :
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
