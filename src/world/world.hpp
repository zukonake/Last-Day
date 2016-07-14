#ifndef WORLD_HPP
#define WORLD_HPP

#include <cstdint>
//
#include <entity/entityContainer.hpp>
#include <world/chunk/chunkContainer.hpp>
#include <world/worldGenerator.hpp>

struct Point;
struct Rectangle;
class ObjectRenderer;
class Dataset;
class Player;

class World : public EntityContainer, public ChunkContainer
{
	const static uint16_t csDaytimeLengthInTicks = 30;
	const static uint16_t csNighttimeLengthInTicks = 20;
	const static uint16_t csDayLengthInTicks = csDaytimeLengthInTicks + csNighttimeLengthInTicks;
public:
	World( const Dataset& dataset, const int& seed ) noexcept;

	void simulate( void ) noexcept;

	Player* createPlayer( const Point& position, const Rectangle& screenSize ) noexcept;

	bool canMove( const Point& target ) noexcept;

	bool isDaytime( void ) const noexcept;
	bool isNighttime( void ) const noexcept;

	const uint16_t& getTick( void ) const noexcept;
private:
	void nextTick( void ) noexcept;

	const Dataset& mDataset;
	const WorldGenerator mGenerator;

	uint16_t mTick = 0;
};

#endif
