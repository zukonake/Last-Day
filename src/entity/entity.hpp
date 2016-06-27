#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <geometry/direction.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <world/world.hpp>

template < typename Subtype > class Entity
{
	friend class EntityProxy;
protected:
	Subtype* subtype;
	Point position;
	World& world;
public:
	virtual void render( ObjectRenderer* renderer, const Point& targetPosition ) const;
	virtual void teleport( const Point& targetPosition );
	virtual void move( const Direction& targetDirection );

	Entity( Subtype* subtype, const Point& position, World& world ) noexcept :
		subtype( subtype ),
		position( position ),
		world( world )
	{

	}
};

template < typename Subtype >
void Entity< Subtype >::render( ObjectRenderer* renderer, const Point& targetPosition ) const
{
	//subtype->render( renderer, targetPosition ); TODO
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

#endif
