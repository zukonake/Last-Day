#ifndef DIRECTION_HPP
#define DIRECTION_HPP

struct Direction
{
	enum Type
	{
		NONE = 0,
		NORTH = 1,
		WEST = 2,
		SOUTH = 3,
		EAST = 4
	};

	Type value;

	virtual void rotateClockwise( void ) noexcept ;
	virtual void rotateCounterClockwise( void ) noexcept;

	Direction( Type value = NONE ) noexcept;
};

#endif
