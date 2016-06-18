#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <geometry/point.hpp>

template < typename Subtype > class Entity
{
protected:
	Point2D position;
	Subtype* subtype;
public:
	void render( Interface* targetInterface, SDL_Rect* targetPosition );
private:
	Entity();
};

#endif
