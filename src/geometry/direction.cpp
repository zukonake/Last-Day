#include "direction.hpp"

void Direction::rotateClockwise( void ) noexcept
{
	switch( value )
	{
	case NONE:
		break;
	case NORTH:
		value = EAST;
		break;
	case WEST:
		value = NORTH;
		break;
	case SOUTH:
		value = WEST;
		break;
	case EAST:
		value = SOUTH;
		break;
	}
	return;
}

void Direction::rotateCounterClockwise( void ) noexcept
{
	switch( value )
	{
	case NONE:
		break;
	case NORTH:
		value = WEST;
		break;
	case WEST:
		value = SOUTH;
		break;
	case SOUTH:
		value = EAST;
		break;
	case EAST:
		value = NORTH;
		break;
	}
	return;
}
