#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>
//
#include <entity/entityContainer.hpp>
#include <world/chunk/chunkContainer.hpp>
#include <world/worldGenerator.hpp>

struct Point;
struct Rectangle;
class ObjectRenderer;
class Dataset;
class Camera;

class World : public ChunkContainer, public EntityContainer
{
public:
	World( const Dataset& dataset, const int& seed ) noexcept;

	void simulate( void ) noexcept;

	Camera* createCamera( const Point& position, const Rectangle& screenSize ) noexcept;
private:
	WorldGenerator mGenerator;
};

#endif
