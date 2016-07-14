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
	const static uint16_t csDaytimeLengthInTicks = 200;
	const static uint16_t csNightLengthInTicks = 100;
	const static uint16_t csDayLengthInTicks = csDaytimeLengthInTicks + csNightLengthInTicks;
public:
	World( const Dataset& dataset, const int& seed ) noexcept;

	void simulate( void ) noexcept;

	Player* createPlayer( const Point& position, const Rectangle& screenSize ) noexcept;

	bool canMove( const Point& target ) noexcept;

	bool isDay( void ) const noexcept;
	bool isNight( void ) const noexcept;

	const uint16_t& getTickClock( void ) const noexcept;
private:
	void nextTick( void ) noexcept;

	const Dataset& mDataset;
	WorldGenerator mGenerator;

	uint16_t mTick;
};

#endif
