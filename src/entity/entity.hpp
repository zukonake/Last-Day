#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <geometry/direction.hpp>
#include <world/world.hpp>

template < typename Subtype > class Entity
{
protected:
	Point position;
	World& world;
	std::shared_ptr < Subtype > subtype;
public:
	virtual void render( SDL_Renderer& targetRenderer, SDL_Rect& targetPosition );
	virtual void teleport( const Point& targetPosition );
	virtual void move( const Direction& targetDirection );

	Entity( const Point& position, World& world, std::shared_ptr < Subtype > subtype );
	virtual ~Entity();
};

template < typename Subtype >
void Entity< Subtype >::render( SDL_Renderer& targetRenderer, SDL_Rect& targetPosition )
{

}

template < typename Subtype >
void Entity< Subtype >::teleport( const Point& targetPosition )
{
	position = targetPosition;
}

template < typename Subtype >
void  Entity< Subtype >::move( const Direction& targetDirection )
{
	position.move( targetDirection );
}

template < typename Subtype >
Entity< Subtype >::Entity( const Point& position, World& world, std::shared_ptr < Subtype > subtype ) :
	position( position ),
	world( world ),
	subtype( subtype )
{

}

template < typename Subtype >
Entity< Subtype >::~Entity()
{

}


#endif
