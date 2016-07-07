#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>
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
	World( const Dataset& dataset, const int& seed ) noexcept;

	void simulate( void ) noexcept;

	const Dataset& getDataset( void ) const noexcept;
	const WorldGenerator& getGenerator( void ) const noexcept;
	const int& getSeed( void ) const noexcept;
private:
	const Dataset& mDataset;
	WorldGenerator mGenerator;
};

#endif
