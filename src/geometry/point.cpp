#include "point.hpp"

Point::Point( std::istream& in ) noexcept
{
	in.ignore( 255, ' ' );
	in >> x;
	in >> y;
}

Point::operator SDL_Rect( void ) const noexcept
{
	SDL_Rect output;
	output.x = x;
	output.y = y;
	return output;
}
Point::operator SDL_Point( void ) const noexcept
{
	SDL_Point output;
	output.x = x;
	output.y = y;
	return output;
}

Point Point::operator * ( const int& mul ) const noexcept
{
	return Point( x * mul, y * mul );
}

Point Point::operator / ( const int& div ) const noexcept
{
	return Point( x / div, y / div );
}

Point Point::operator % ( const int& mod ) const noexcept
{
	return Point( x % mod, y % mod );
}

Point Point::operator + ( const int& add ) const noexcept
{
	return Point( x + add, y + add );
}

Point Point::operator - ( const int& sub ) const noexcept
{
	return Point( x - sub, y - sub );
}

bool Point::operator == ( const Point& target ) const noexcept
{
	return x == target.x and y == target.y;
}

bool Point::operator < ( const Point& target ) const noexcept
{
	return (x < target.x) or (x == target.x and y < target.y);
}

void Point::move( const Direction& direction, const int& difference ) noexcept
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
		break;
	}
	return;
}

Point Point::tilePosition( const uint16_t& sizeInTiles ) const noexcept
{
	return *this * sizeInTiles;
}

Point Point::chunkPosition( const uint16_t& sizeInTiles ) const noexcept
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

Point Point::internalPosition( const uint16_t& sizeInTiles ) const noexcept
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
