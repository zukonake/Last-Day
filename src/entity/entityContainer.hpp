#ifndef ENTITYCONTAINTER_HPP
#define ENTITYCONTAINTER_HPP

#include <memory>
#include <vector>
//
#include <nonCopyable.hpp>
#include <world/chunk/chunkContainer.hpp>

struct Point;
class Entity;

class EntityContainer : NonCopyable
{
	typedef std::vector< std::shared_ptr< Entity > > tEntityVector;
public:
	EntityContainer( ChunkContainer& chunkContainer ) noexcept : mChunkContainer( chunkContainer ) { }

	virtual ~EntityContainer( void ) noexcept { }

	void simulate( void ) noexcept;

	void addEntity( std::shared_ptr< Entity > value );
private:
	tEntityVector mEntities;
	ChunkContainer& mChunkContainer;
};

#endif
