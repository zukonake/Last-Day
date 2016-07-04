#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <geometry/direction.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <entity/entitySubtype.hpp>

class World;

class Entity
{
public:
	Entity( World& world, const Point& position, const EntitySubtype* subtype ) noexcept;
	virtual ~Entity( void ) noexcept { }

	virtual void render( ObjectRenderer* renderer, const SDL_Rect& targetPosition ) const;
	virtual void teleport( const Point& targetPosition ) noexcept;
	virtual void move( const Direction& targetDirection ) noexcept;

	const std::string& getName( void ) const noexcept;
	const Point& getPosition( void ) const noexcept;
protected:
	World& world;
	Point position;
private:
	const EntitySubtype* subtype;
};

#endif
