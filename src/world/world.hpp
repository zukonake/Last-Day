#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>
#include <memory>
#include <iostream>
#include <map>
#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <world/tile.hpp>
#include <world/chunk.hpp>
#include <data/dataset.hpp>
#include <world/worldGenerator.hpp>

class World
{
	typedef std::map< Point::coordinate, std::map< Point::coordinate, std::shared_ptr< Chunk > > > ChunkMap2D;
	const static uint8_t chunkLoadingRange = 1;

	ChunkMap2D loadedChunks;
	WorldGenerator generator;
	Dataset& dataset;
protected:
	std::shared_ptr< Chunk > getChunk( const Point& targetTilePosition );
	std::shared_ptr< Chunk > loadChunk( const Point& targetChunkPosition );
public:
	void renderTile( const Point& targetTilePosition, SDL_Renderer* targetRenderer, SDL_Rect& targetRenderPositionn );

	World( Dataset& dataset );
	~World();

	Tile* operator()( const Point& targetTilePosition );
};

#endif
