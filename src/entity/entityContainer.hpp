#ifndef ENTITYCONTAINTER_HPP
#define ENTITYCONTAINTER_HPP

#include <memory>
#include <vector>
//
#include <world/chunk/chunkContainer.hpp>

struct Point;
class Entity;

class EntityContainer
{
	typedef std::vector< std::shared_ptr< Entity > > entityVector;
public:
	EntityContainer( const EntityContainer& that ) = delete;
	EntityContainer( ChunkContainer& chunkContainer ) noexcept : chunkContainer( chunkContainer ) { }

	virtual ~EntityContainer( void ) noexcept { }

	EntityContainer& operator=( const EntityContainer& that ) = delete;

	void simulate( void ) noexcept;

	void addEntity( std::shared_ptr< Entity > value );
private:
	entityVector entities;
	ChunkContainer& chunkContainer;
};

#endif
