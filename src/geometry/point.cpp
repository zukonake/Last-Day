#include "point.hpp"

Point2D Point2D::operator * ( const int& multiplier ) const
{
	return Point2D( this->x * multiplier, this->y * multiplier );
}

Point2D Point2D::operator / ( const int& divider ) const
{
	return Point2D( this->x / divider, this->y / divider );
}

Point2D Point2D::operator % ( const int& modulus ) const
{
	return Point2D( this->x % modulus, this->y % modulus );
}

std::istream& operator >> ( std::istream& in, Point2D& obj )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> obj.x;
	in >> obj.y;
	return in;
}

std::ostream& operator << ( std::ostream& out, const Point2D& obj )
{
	return out;
}

Point3D Point3D::operator * ( const int& multiplier ) const
{
	return Point3D( this->x * multiplier, this->y * multiplier, this->z / multiplier );
}

Point3D Point3D::operator / ( const int& divider ) const
{
	return Point3D( this->x / divider, this->y / divider, this->z / divider );
}

Point3D Point3D::operator % ( const int& modulus ) const
{
	return Point3D( this->x % modulus, this->y % modulus, this->z % modulus );
}

std::istream& operator >> ( std::istream& in, Point3D& obj )
{
	const unsigned int maximumVariableLength = 256;
	in.ignore( maximumVariableLength, ' ' );
	in >> static_cast< Point2D& >( obj );
	in >> obj.z;
	return in;
}

std::ostream& operator << ( std::ostream& out, const Point3D& obj )
{
	return out;
}
