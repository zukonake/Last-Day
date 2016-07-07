#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
//
#include <geometry/point.hpp>

struct Direction;
class ObjectRenderer;
class EntitySubtype;
class World;

class Entity : public sf::Drawable
{
public:
	Entity( World& world, const Point& position, const EntitySubtype* subtype ) noexcept;
	virtual ~Entity( void ) noexcept { }

	void teleport( const Point& targetPosition ) noexcept;
	virtual void move( const Direction& targetDirection );

	const std::string& getName( void ) const noexcept;
	const Point& getPosition( void ) const noexcept;
protected:
	World& mWorld;
	Point mPosition;
private:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override;

	const EntitySubtype* pSubtype;
};

#endif
