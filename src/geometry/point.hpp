#ifndef POINT_HPP
#define POINT_HPP

#include <cstdint>
//
#include <geometry/direction.hpp>

struct Point
{
	typedef int32_t coordinate;

	coordinate x;
	coordinate y;

	void move( const Direction& direction, const int& difference = 1 );

	Point tilePosition( const uint16_t& sizeInTiles ) const;
	Point chunkPosition( const uint16_t& sizeInTiles ) const;
	Point internalPosition( const uint16_t& sizeInTiles ) const;

	double getDistanceTo( const Point& target );

	Point( const coordinate& x, const coordinate& y ) : x(x), y(y) { }
	Point() { }

	Point operator * ( const int& mul ) const;
	Point operator / ( const int& div ) const;
	Point operator % ( const int& mod ) const;
	Point operator + ( const int& add ) const;
	Point operator - ( const int& sub ) const;

	inline bool operator == ( const Point& target ) const;
};

bool Point::operator == ( const Point& target ) const
{
	return this->x == target.x && this->y == target.y;
}

#endif
