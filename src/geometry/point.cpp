#include "point.hpp"
#include <iostream>

void Point::move( const Direction& direction, const int& difference )
{
	switch( direction.value )
	{
		case Direction::NONE:
		break;

		case Direction::NORTH:
			y -= difference;
		break;

		case Direction::WEST:
			x -= difference;
		break;

		case Direction::SOUTH:
			y += difference;
		break;

		case Direction::EAST:
			x += difference;
		break;

		default:
			std::cout << "ERROR: default case called in Point::move()\n";
		break;
	}
}

Point Point::tilePosition( const uint16_t& sizeInTiles ) const
{
	Point output = *this;
	output = output * sizeInTiles;
	return output;
}

Point Point::chunkPosition( const uint16_t& sizeInTiles ) const
{
	Point output = *this;
	if( output.x < 0 )
	{
		output.x -= sizeInTiles - 1;
	}
	if( output.y < 0 )
	{
		output.y -= sizeInTiles - 1;
	}
	output = output / sizeInTiles;
	return output;
}

Point Point::internalPosition( const uint16_t& sizeInTiles ) const
{
	Point output = *this;
	output = output % sizeInTiles;
	if( output.x < 0 )
	{
		output.x +=sizeInTiles;
	}
	if( output.y < 0 )
	{
		output.y += sizeInTiles;
	}
	return output;
}

Point Point::operator * ( const int& mul ) const
{
	return Point( x * mul, y * mul );
}

Point Point::operator / ( const int& div ) const
{
	return Point( x / div, y / div );
}

Point Point::operator % ( const int& mod ) const
{
	return Point( x % mod, y % mod );
}

Point Point::operator + ( const int& add ) const
{
	return Point( x + add, y + add );
}

Point Point::operator - ( const int& sub ) const
{
	return Point( x - sub, y - sub );
}
