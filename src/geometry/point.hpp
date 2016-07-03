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

	Point( const coordinate& x, const coordinate& y ) noexcept : x(x), y(y) { }
	Point( std::istream& in ) noexcept;
	Point( void ) noexcept { }

	virtual operator SDL_Rect( void ) const noexcept;
	virtual operator SDL_Point( void ) const noexcept;

	Point operator * ( const int& mul ) const noexcept;
	Point operator / ( const int& div ) const noexcept;
	Point operator % ( const int& mod ) const noexcept;
	Point operator + ( const int& add ) const noexcept;
	Point operator - ( const int& sub ) const noexcept;

	bool operator == ( const Point& target ) const noexcept;
	bool operator < ( const Point& target ) const noexcept;

	void move( const Direction& direction, const int& difference = 1 ) noexcept;

	Point tilePosition( const uint16_t& sizeInTiles ) const noexcept;
	Point chunkPosition( const uint16_t& sizeInTiles ) const noexcept;
	Point internalPosition( const uint16_t& sizeInTiles ) const noexcept;

	coordinate x;
	coordinate y;
};



#endif
