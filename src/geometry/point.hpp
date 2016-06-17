#ifndef POINT_HPP
#define POINT_HPP

struct Point2D
{
	typedef int coordinate;
	coordinate x;
	coordinate y;
	Point2D( coordinate x, coordinate y ) : x(x), y(y) { }
};

struct Point3D : public Point2D
{
	coordinate z;
	Point3D( coordinate x, coordinate y, coordinate z ) : x(x), y(y), z(z) { }
};

#endif
