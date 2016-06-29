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
#include <entity/entitySubtype.hpp>

class Entity
{
	friend class EntityProxy;
protected:
	EntitySubtype* subtype;
	Point position;
	World& world;
public:
	virtual void render( ObjectRenderer* renderer, const Point& targetPosition ) const;
	virtual void teleport( const Point& targetPosition ) noexcept;
	virtual void move( const Direction& targetDirection ) noexcept;

	const Point& getPosition( void ) const noexcept { return position; }

	Entity( EntitySubtype* subtype, const Point& position, World& world ) noexcept :
		subtype( subtype ),
		position( position ),
		world( world )
	{

	}

	virtual ~Entity() noexcept {};
};

#endif
