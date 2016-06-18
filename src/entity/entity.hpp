#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <geometry/point.hpp>

template < typename Subtype > class Entity
{
	Point2D position;
	Subtype* subtype;
	void render( Interface* targetInterface, SDL_Rect* targetPosition );
};

#endif
