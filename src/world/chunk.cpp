#include "chunk.hpp"

Chunk::Chunk( const Point2D& position ) : position( position )
{

}

Tile& Chunk::operator()( const Point2D& targetInternalPosition )
{
	return *tiles[ targetInternalPosition.x ][ targetInternalPosition.y ];
}
