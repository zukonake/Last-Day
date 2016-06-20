#include "chunk.hpp"

Tile* Chunk::operator()( Point2D targetInternalPosition )
{
	return tiles[ targetInternalPosition.x ][ targetInternalPosition.y ];
}

Chunk::Chunk( Point2D position ) : position( position )
{

}
