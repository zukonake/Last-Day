#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <cstdint>
#include <iostream>
#include <SFML/System.hpp>
//
#include <geometry/point.hpp>

struct Rectangle : public Point
{
	using Point::Point;
	using Point::operator+;
	using Point::operator-;
	using Point::operator*;
	using Point::operator/;
	using Point::operator%;
	using Point::operator==;
	using Point::operator>=;
	using Point::operator>;
	using Point::operator<;
	using Point::operator<=;
	using Point::operator=;

	Point::coordinate& width = Point::x; //
	Point::coordinate& height = Point::y; //TODO width, height should be unsigned
};

#endif
