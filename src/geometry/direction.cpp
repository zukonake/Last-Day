#include "direction.hpp"

Direction::operator DirectionType( void ) const noexcept
{
	return type;
}

void Direction::rotateClockwise( void ) noexcept
{
	if( type == DirectionType::NORTH )
	{
		type = DirectionType::EAST;
	}
	else
	{
		type = static_cast< DirectionType >( ( int )type - 1 );
	}
	return;
}

void Direction::rotateCounterClockwise( void ) noexcept
{
	if( type == DirectionType::EAST )
	{
		type = DirectionType::NORTH;
	}
	else
	{
		type = static_cast< DirectionType >( ( int )type + 1 );
	}
	return;
}
