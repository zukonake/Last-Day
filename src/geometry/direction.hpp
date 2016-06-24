#ifndef DIRECTION_HPP
#define DIRECTION_HPP

struct Direction
{
	enum Type
	{
		NONE,
		NORTH,
		WEST,
		SOUTH,
		EAST,
	};

	Type value;

	virtual void rotateClockwise();
	virtual void rotateCounterClockwise();

	Direction( Type value = NONE );
};

#endif
