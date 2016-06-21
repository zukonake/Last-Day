#ifndef POINT_HPP
#define POINT_HPP

#include <cstdint>
#include <iostream>

struct Point2D
{
	typedef int16_t coordinate;

	coordinate x;
	coordinate y;

	Point2D( const coordinate& x, const coordinate& y ) : x(x), y(y) { }
	Point2D() { }

	Point2D operator * ( const int& multiplier ) const;
	Point2D operator / ( const int& divider ) const;
	Point2D operator % ( const int& modulus ) const;

	inline bool operator == ( const Point2D& target ) const;

	friend std::istream& operator >> ( std::istream& in, Point2D& obj );
	friend std::ostream& operator << ( std::ostream& out, const Point2D& obj );
};

bool Point2D::operator == ( const Point2D& target ) const
{
	return this->x == target.x && this->y == target.y;
}

struct Point3D : public Point2D
{
	coordinate z;

	Point3D( const coordinate& x, const coordinate& y, const coordinate& z ) : Point2D( x, y ), z(z) { }
	Point3D() { }

	Point3D operator * ( const int& multiplier ) const;
	Point3D operator / ( const int& divider ) const;
	Point3D operator % ( const int& modulus ) const;

	inline bool operator == ( const Point3D& target ) const;

	friend std::istream& operator >> ( std::istream& in, Point3D& obj );
	friend std::ostream& operator << ( std::ostream& out, const Point3D& obj );
};

bool Point3D::operator == ( const Point3D& target ) const
{
	return this->x == target.x && this->y == target.y && this->z == target.z;
}

#endif
