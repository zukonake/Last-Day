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
};

struct Point3D : public Point2D
{
	coordinate z;
	Point3D( coordinate x, coordinate y, coordinate z ) : Point2D( x, y ), z(z) { }
	friend std::istream& operator >> ( std::istream& in, Point3D& obj );
	friend std::ostream& operator << ( std::ostream& out, const Point3D& obj );
};

#endif
