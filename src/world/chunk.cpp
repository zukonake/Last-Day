#include "chunk.hpp"

Point2D Chunk::transformPositionToChunkPosition( const Point2D& targetTilePosition )
{
	return targetTilePosition * chunkSizeInTiles;
}

Point2D Chunk::transformPositionToInternalPosition( const Point2D& targetTilePosition )
{
	return targetTilePosition % chunkSizeInTiles;
}

Point2D Chunk::transformPositionToTilePosition( const Point2D& targetChunkPosition )
{
	return targetChunkPosition / chunkSizeInTiles;
}

Chunk::Chunk( const Point2D& position ) : position( position )
{

}

Tile* Chunk::operator()( const Point2D& targetInternalPosition )
{
	return tiles[ targetInternalPosition.x ][ targetInternalPosition.y ];
}
