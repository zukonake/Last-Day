#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>
#include <SDL2/SDL.h>
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

	void renderHeightEffects( const Point& targetTilePosition, ObjectRenderer* objectRenderer, SDL_Rect& targetRenderPosition ) noexcept;

	void simulate( void ) noexcept;

	const Dataset& getDataset( void ) const noexcept;
private:
	const Dataset& dataset;
	WorldGenerator generator;
};

#endif
