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
	World( Dataset& dataset ) noexcept;

	void renderHeightEffects( const Point& targetTilePosition, sf::RenderWindow& window, const Point& targetRenderPosition ) noexcept;

	void simulate( void ) noexcept;

	Dataset& getDataset( void ) const noexcept;
private:
	Dataset& dataset;
	WorldGenerator generator;
};

#endif
