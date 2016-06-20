#ifndef POINT_HPP
#define POINT_HPP

#include <cstdint>
#include <iostream>

struct Point2D
{
	typedef int16_t coordinate;
	coordinate x;
	coordinate y;
	Point2D( coordinate x, coordinate y ) : x(x), y(y) { }
	friend std::istream& operator >> ( std::istream& in, Point2D& obj );
	friend std::ostream& operator << ( std::ostream& out, const Point2D& obj );
	bool operator == ( const Point2D& target );
	Point2D operator * ( const int& multiplier );
	Point2D operator / ( const int& divider );
	Point2D operator % ( const int& modulus );
};

struct Point3D : public Point2D
{
	coordinate z;
	Point3D( coordinate x, coordinate y, coordinate z ) : Point2D( x, y ), z(z) { }
	friend std::istream& operator >> ( std::istream& in, Point3D& obj );
	friend std::ostream& operator << ( std::ostream& out, const Point3D& obj );
	bool operator == ( const Point3D& target );
	Point3D operator * ( const int& multiplier );
	Point3D operator / ( const int& divider );
	Point3D operator % ( const int& modulus );
};

#endif
