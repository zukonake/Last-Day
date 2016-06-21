#ifndef DIRECTION_HPP
#define DIRECTION_HPP

#include <geometry/point.hpp>

struct Direction
{
	enum DirectionType
	{
		NORTH,
		NORTHWEST,
		WEST,
		SOUTHWEST,
		SOUTH,
		SOUTHEAST,
		EAST,
		NORTHEAST
	};

	virtual Point2D movePosition( const DirectionType& direction, const Point2D& targetPosition, const int& difference );
public:
	virtual DirectionType rotateClockwise( const DirectionType& direction );
	virtual DirectionType rotateCounterClockwise( const DirectionType& direction );

	Direction();
};

#endif
