#ifndef DIRECTION_HPP
#define DIRECTION_HPP

struct Direction
{
	enum eType
	{
		NONE = 0,
		NORTH = 1,
		WEST = 2,
		SOUTH = 3,
		EAST = 4
	};

	Direction( eType type = NONE ) noexcept : type( type ) { }

	virtual void rotateClockwise( void ) noexcept ;
	virtual void rotateCounterClockwise( void ) noexcept;

	eType type;
};

#endif
