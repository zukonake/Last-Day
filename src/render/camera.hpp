#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <geometry/point.hpp>

class Camera
{
	World* world;
	Point2D* position;
	unsigned int viewRange;
	void render();
};

#endif
