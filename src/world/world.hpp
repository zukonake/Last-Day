#ifndef WORLD_HPP
#define WORLD_HPP

#include <cmath>
#include <cstdint>
#include <memory>
#include <iostream>
#include <map>
#include <vector>
#include <SDL2/SDL.h>
//
#include <geometry/point.hpp>
#include <render/objectRenderer/objectRenderer.hpp>
#include <entity/entity.hpp>
#include <world/tile.hpp>
#include <world/chunk.hpp>
#include <data/dataset.hpp>
#include <entity/entityAI.hpp>
#include <world/worldGenerator.hpp>

class World
{
	typedef std::map< Point::coordinate, std::map< Point::coordinate, std::shared_ptr< Chunk > > > ChunkMap2D;
	typedef std::vector< std::shared_ptr< Entity > > EntityVector;
	const static uint8_t chunkLoadingRange = 1;

	ChunkMap2D loadedChunks;
	EntityVector entities;
	Dataset& dataset;
	WorldGenerator generator;
	EntityAI entityAI;
protected:
	std::shared_ptr< Chunk > getChunk( const Point& targetTilePosition );
	void unloadChunk( const Point& targetChunkPosition );
	std::shared_ptr< Chunk > loadChunk( const Point& targetChunkPosition );
public:
	void renderTile( const Point& targetTilePosition, ObjectRenderer* objectRenderer, SDL_Rect& targetRenderPositionn );

	void simulate( void );
	void simulateEntities( void );

	World( Dataset& dataset );
	~World();

	void unloadChunks( void );
	void unloadEntities( void );

	std::shared_ptr< Tile > operator()( const Point& targetTilePosition );
};

#endif
