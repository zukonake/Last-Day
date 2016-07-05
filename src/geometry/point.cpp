#include "point.hpp"
#include <geometry/direction.hpp>

Point::Point( std::istream& in ) noexcept
{
	in.ignore( 255, ' ' );
	in >> x;
	in >> y;
}

Point::operator sf::Vector2< float >( void ) const noexcept
{
	return sf::Vector2< float >( (float) x, (float) y );
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

Point Point::move( const Direction& direction, const int& difference ) noexcept
{
	Point output = *this;
	switch( direction.value )
	{
		case Direction::NONE:
		break;

		case Direction::NORTH:
			output.y -= difference;
		break;

		case Direction::WEST:
			output.x -= difference;
		break;

		case Direction::SOUTH:
			output.y += difference;
		break;

		case Direction::EAST:
			output.x += difference;
		break;

		default:
		break;
	}
	return output;
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
