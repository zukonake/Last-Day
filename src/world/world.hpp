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

class World : public EntityContainer
{
	//Dataset& dataset;
	ChunkContainer chunkContainer;
public:
	void renderHeightEffects( const Point& targetTilePosition, ObjectRenderer* objectRenderer, SDL_Rect& targetRenderPositionn );
	Tile& getTile( const Point& targetTilePosition );
	void simulate( void );

	World( Dataset& dataset );
	~World();
};

#endif
