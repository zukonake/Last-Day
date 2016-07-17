#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <entity/camera.hpp>

struct Point;
struct Rectangle;
class Dataset;

class Player : public Camera
{
public:
	Player( const Point& position, World& world, const Rectangle& screenSize, const Dataset& dataset ) noexcept;

	void placeEntity( const Point& position ) noexcept; //TODO delet this
private:
	const Dataset& mDataset;
};

#endif
