#include "world.hpp"

std::shared_ptr< Chunk > World::getChunk( const Point& targetTilePosition )
{
	Point targetChunkPosition = targetTilePosition.chunkPosition( Chunk::sizeInTiles );
	if( !loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ] )
	{
		loadChunk( targetChunkPosition );
	}
	return loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ];
}

std::shared_ptr< Chunk > World::loadChunk( const Point& targetChunkPosition )
{
	std::cout << "INFO: Loading chunk: " << targetChunkPosition.x << ", " << targetChunkPosition.y << "\n";
	loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ] = std::make_shared< Chunk > ( Chunk() );
	generator.generateChunk( *loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ], dataset, targetChunkPosition );
	return loadedChunks[ targetChunkPosition.x ][ targetChunkPosition.y ];
}

void World::unloadChunk( const Point& targetChunkPosition )
{

}

void World::renderTile( const Point& targetTilePosition, ObjectRenderer* objectRenderer, SDL_Rect& targetRenderPosition )
{
	Tile* targetTile = this->operator()( targetTilePosition );
	targetTile->render( objectRenderer, targetRenderPosition );
	SDL_SetRenderDrawColor( objectRenderer->getRenderer(), 0, 0, 0, 220 - ( ( targetTile->getHeight() + 26) * 4 ) ) ;
	SDL_RenderFillRect( objectRenderer->getRenderer(), &targetRenderPosition );
	SDL_SetRenderDrawColor( objectRenderer->getRenderer(), 0, 0, 0, 63 );
	if( this->operator()( Point( targetTilePosition.x - 1, targetTilePosition.y ) )->getHeight() != targetTile->getHeight() )
	{
		SDL_RenderDrawLine( objectRenderer->getRenderer(),
			targetRenderPosition.x,
			targetRenderPosition.y,
			targetRenderPosition.x,
			targetRenderPosition.y + targetRenderPosition.h);
	}
	if( this->operator()( Point( targetTilePosition.x, targetTilePosition.y - 1) )->getHeight() != targetTile->getHeight() )
	{
		SDL_RenderDrawLine( objectRenderer->getRenderer(),
			targetRenderPosition.x,
			targetRenderPosition.y,
			targetRenderPosition.x + targetRenderPosition.w,
			targetRenderPosition.y);
	}
}

World::World( Dataset& dataset ) : dataset( dataset )
{

}

World::~World()
{
	for( auto iteratorY = loadedChunks.begin(); iteratorY != loadedChunks.end(); iteratorY++ )
	{
		for( auto iteratorX = iteratorY->second.begin(); iteratorX != iteratorY->second.end(); iteratorX++ )
		{
			iteratorX->second.reset();
		}
	}
}

Tile* World::operator()( const Point& targetTilePosition )
{
	Point targetInternalPosition = targetTilePosition.internalPosition( Chunk::sizeInTiles );
	return &getChunk( targetTilePosition )->tiles[ targetInternalPosition.x ][ targetInternalPosition.y ];
}
