#ifndef POINT_HPP
#define POINT_HPP

#include <cstdint>
#include <iostream>
#include <SDL2/SDL.h>
//
#include <geometry/direction.hpp>

struct Point
{
	typedef int32_t coordinate;

	coordinate x;
	coordinate y;

	void move( const Direction& direction, const int& difference = 1 ) noexcept;

	inline Point tilePosition( const uint16_t& sizeInTiles ) const noexcept;
	Point chunkPosition( const uint16_t& sizeInTiles ) const noexcept;
	Point internalPosition( const uint16_t& sizeInTiles ) const noexcept;

	double getDistanceTo( const Point& target ) noexcept;

	Point( const coordinate& x, const coordinate& y ) noexcept : x(x), y(y) { }
	Point( std::istream& in ) noexcept;
	Point( void ) noexcept { }

	Point operator * ( const int& mul ) const noexcept;
	Point operator / ( const int& div ) const noexcept;
	Point operator % ( const int& mod ) const noexcept;
	Point operator + ( const int& add ) const noexcept;
	Point operator - ( const int& sub ) const noexcept;

	inline bool operator == ( const Point& target ) const noexcept;

	virtual operator SDL_Rect( void ) const noexcept;
	virtual operator SDL_Point( void ) const noexcept;
};

Point Point::tilePosition( const uint16_t& sizeInTiles ) const noexcept
{
	return *this * sizeInTiles;
}

bool Point::operator == ( const Point& target ) const noexcept
{
	return x == target.x and y == target.y;
}

#endif
