#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <iostream>
#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <geometry/direction.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <entity/entitySubtype.hpp>

class Entity
{
	friend class EntityProxy;
public:
	enum aiType
	{
		none
	};
protected:
	EntitySubtype* subtype;
	Point position;
public:
	virtual void render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const;
	virtual void teleport( const Point& targetPosition ) noexcept;
	virtual void move( const Direction& targetDirection ) noexcept;

	const std::string& getName( void ) const noexcept { return subtype->getName(); }
	Point& getPosition( void ) noexcept { return position; }

	Entity( EntitySubtype* subtype, const Point& position ) noexcept :
		subtype( subtype ),
		position( position )
	{

	}

	virtual ~Entity() noexcept {};
};

#endif
