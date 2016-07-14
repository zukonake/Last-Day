#ifndef DIRECTION_HPP
#define DIRECTION_HPP

enum class DirectionType
{
	NORTH = 0,
	WEST = 1,
	SOUTH = 2,
	EAST = 3
};

struct Direction
{
	Direction( DirectionType type ) noexcept : type( type ) { }

	virtual operator DirectionType( void ) const noexcept;

	virtual void rotateClockwise( void ) noexcept;
	virtual void rotateCounterClockwise( void ) noexcept;

	DirectionType type;
};

#endif
