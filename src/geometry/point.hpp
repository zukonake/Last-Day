#ifndef POINT_HPP
#define POINT_HPP

#include <cstdint>
#include <iostream>

struct Direction;

namespace sf
{
	template < typename T >
	class Vector2;
}

struct Point
{
	friend std::ostream& operator<<( std::ostream& out, const Point& obj );
	friend std::istream& operator>>( std::istream& in, Point& obj );
	typedef int32_t coordinate;

	Point( const coordinate& x, const coordinate& y ) noexcept : x( x ), y( y ) { }
	explicit Point( std::istream& in ) noexcept;
	Point( const sf::Vector2< float >& that ) noexcept;
	Point( const sf::Vector2< int >& that ) noexcept;
	Point( void ) noexcept : x( 0 ), y ( 0 ) { }

	virtual ~Point( void ) = default;

	virtual operator sf::Vector2< float >( void ) const noexcept;
	virtual operator sf::Vector2< int >( void ) const noexcept;

	virtual Point operator*( const Point& mul ) const noexcept;
	virtual Point operator/( const Point& div ) const noexcept;
	virtual Point operator%( const Point& mod ) const noexcept;
	virtual Point operator+( const Point& add ) const noexcept;
	virtual Point operator-( const Point& sub ) const noexcept;
	virtual Point operator*( const int& mul ) const noexcept;
	virtual Point operator/( const int& div ) const noexcept;
	virtual Point operator%( const int& mod ) const noexcept;
	virtual Point operator+( const int& add ) const noexcept;
	virtual Point operator-( const int& sub ) const noexcept;

	virtual bool operator==( const Point& target ) const noexcept;
	virtual bool operator<=( const Point& target ) const noexcept;
	virtual bool operator<( const Point& target ) const noexcept;
	virtual bool operator>( const Point& target ) const noexcept;
	virtual bool operator>=( const Point& target ) const noexcept;

	Point move( const Direction& direction, const int& difference = 1 ) noexcept;

	virtual Point tilePosition( const uint16_t& sizeInTiles ) const noexcept final;
	virtual Point chunkPosition( const uint16_t& sizeInTiles ) const noexcept final;
	virtual Point internalPosition( const uint16_t& sizeInTiles ) const noexcept final;

	coordinate x;
	coordinate y;
};



#endif
