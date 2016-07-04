#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>
#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <data/dataset.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <entity/entityContainer.hpp>
#include <world/chunk/chunkContainer.hpp>
#include <world/worldGenerator.hpp>

class World : public EntityContainer
{
public:
	World( Dataset& dataset ) noexcept;

	void renderHeightEffects( const Point& targetTilePosition, ObjectRenderer* objectRenderer, SDL_Rect& targetRenderPosition ) noexcept;

	void simulate( void ) noexcept;

	const Dataset& getDataset( void ) const noexcept;
	Tile& getTile( const Point& targetTilePosition ) noexcept;
private:
	Dataset& dataset;
	WorldGenerator generator;
	ChunkContainer chunkContainer;
};

#endif
