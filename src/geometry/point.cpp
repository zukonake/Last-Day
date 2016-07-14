#include "point.hpp"
#include <SFML/System/Vector2.hpp>
//
#include <geometry/direction.hpp>

std::ostream& operator<<( std::ostream& out, const Point& obj )
{
	out << obj.x << " , " << obj.y;
	return out;
}

std::istream& operator>>( std::istream& in, Point& obj )
{
	in >> obj.x;
	in.ignore( 255, ' ' );
	in >> obj.y;
	return in;
}

Point::Point( std::istream& in ) noexcept
{
	in.ignore( 255, ' ' );
	in >> x;
	in >> y;
}

Point::Point( const sf::Vector2< float >& that ) noexcept :
	x( ( coordinate )that.x ),
	y( ( coordinate )that.y )
{

}

Point::Point( const sf::Vector2< int >& that ) noexcept :
	x( ( coordinate )that.x ),
	y( ( coordinate )that.y )
{

}

Point::operator sf::Vector2< float >( void ) const noexcept
{
	return sf::Vector2< float >( ( float ) x, ( float ) y );
}

Point::operator sf::Vector2< int >( void ) const noexcept
{
	return sf::Vector2< int >( ( int ) x, ( int ) y );
}

Point Point::operator*( const Point& mul ) const noexcept
{
	return Point( x * mul.x, y * mul.y );
}

Point Point::operator/( const Point& div ) const noexcept
{
	return Point( x / div.x, y / div.y );
}

Point Point::operator%( const Point& mod ) const noexcept
{
	return Point( x % mod.x, y % mod.y );
}

Point Point::operator+( const Point& add ) const noexcept
{
	return Point( x + add.x, y + add.y );
}

Point Point::operator-( const Point& sub ) const noexcept
{
	return Point( x - sub.x, y - sub.y );
}

Point Point::operator*( const int& mul ) const noexcept
{
	return Point( x * mul, y * mul );
}

Point Point::operator/( const int& div ) const noexcept
{
	return Point( x / div, y / div );
}

Point Point::operator%( const int& mod ) const noexcept
{
	return Point( x % mod, y % mod );
}

Point Point::operator+( const int& add ) const noexcept
{
	return Point( x + add, y + add );
}

Point Point::operator-( const int& sub ) const noexcept
{
	return Point( x - sub, y - sub );
}

bool Point::operator==( const Point& target ) const noexcept
{
	return x == target.x and y == target.y;
}

bool Point::operator<=( const Point& target ) const noexcept
{
	return (x <= target.x) or (x == target.x and y <= target.y);
}

bool Point::operator<( const Point& target ) const noexcept
{
	return (x < target.x) or (x == target.x and y < target.y);
}

bool Point::operator>( const Point& target ) const noexcept
{
	return (x > target.x) or (x == target.x and y > target.y);
}

bool Point::operator>=( const Point& target ) const noexcept
{
	return (x >= target.x) or (x == target.x and y >= target.y);
}

Point Point::move( const Direction& direction, const int& difference ) noexcept
{
	Point output = *this;
	switch( direction.type )
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
