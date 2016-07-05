#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>
//
#include <entity/entityContainer.hpp>
#include <world/chunk/chunkContainer.hpp>
#include <world/worldGenerator.hpp>

struct Point;
class ObjectRenderer;
class Dataset;

class World : public ChunkContainer, public EntityContainer
{
public:
	World( const Dataset& dataset ) noexcept;

	void renderHeightEffects( const Point& targetTilePosition, sf::RenderWindow& window, const Point& targetRenderPosition ) noexcept;

	void simulate( void ) noexcept;

	const Dataset& getDataset( void ) const noexcept;
private:
	const Dataset& dataset;
	WorldGenerator generator;
};

#endif
