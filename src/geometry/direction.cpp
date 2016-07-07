#include "direction.hpp"

void Direction::rotateClockwise( void ) noexcept
{
	switch( type )
	{
	case NONE:
		break;
	case NORTH:
		type = EAST;
		break;
	case WEST:
		type = NORTH;
		break;
	case SOUTH:
		type = WEST;
		break;
	case EAST:
		type = SOUTH;
		break;
	}
	return;
}

void Direction::rotateCounterClockwise( void ) noexcept
{
	switch( type )
	{
	case NONE:
		break;
	case NORTH:
		type = WEST;
		break;
	case WEST:
		type = SOUTH;
		break;
	case SOUTH:
		type = EAST;
		break;
	case EAST:
		type = NORTH;
		break;
	}
	return;
}
