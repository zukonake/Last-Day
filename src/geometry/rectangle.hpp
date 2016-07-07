#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cstdint>
#include <iostream>

struct Rectangle
{
	Rectangle( const uint16_t& width, const uint16_t& height ) noexcept : width( width ), height( height ) { }
	Rectangle( std::istream& in ) noexcept ;
	Rectangle( void ) noexcept { }

	Rectangle operator * ( const int& mul ) const noexcept;
	Rectangle operator / ( const int& div ) const noexcept;
	Rectangle operator % ( const int& mod ) const noexcept;
	Rectangle operator + ( const int& add ) const noexcept;
	Rectangle operator - ( const int& sub ) const noexcept;

	bool operator == ( const Rectangle& target ) const noexcept;

	uint16_t width;
	uint16_t height;
};

#endif
