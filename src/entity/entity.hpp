#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
//
#include <geometry/point.hpp>

struct Direction;
class ObjectRenderer;
class EntitySubtype;
class World;

class Entity
{
public:
	Entity( World& world, const Point& position, const EntitySubtype* subtype ) noexcept;
	virtual ~Entity( void ) noexcept { }

	void render( sf::RenderWindow& window, const Point& targetPosition ) const;
	void teleport( const Point& targetPosition ) noexcept;
	virtual void move( const Direction& targetDirection );

	const std::string& getName( void ) const noexcept;
	const Point& getPosition( void ) const noexcept;
protected:
	World& world;
	Point position;
private:
	const EntitySubtype* subtype;
};

#endif
