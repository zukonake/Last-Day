#include "world.hpp"
#include <SFML/Graphics.hpp>
//
#include <geometry/direction.hpp>
#include <geometry/point.hpp>
#include <data/dataset.hpp>
#include <world/worldGenerator.hpp>
#include <core/player.hpp>

World::World( const Dataset& dataset, const int& seed ) noexcept :
	EntityContainer(),
	ChunkContainer( mGenerator, static_cast< EntityContainer& >( *this ) ),
	mDataset( dataset ),
	mGenerator( *this, mDataset, seed )
{

}

Player* World::createPlayer( const Point& position, const Point& windowSize ) noexcept
{
	return new Player( position, *this, windowSize, mDataset );
}

void World::simulate( void ) noexcept
{
	EntityContainer::simulate();
	ChunkContainer::unloadInactiveChunks();
	nextTick();
	return;
}

bool World::canMove( const Point& target ) noexcept
{
	return getEntity( target ) == nullptr and getTile( target ).getSubtype()->getIsPassable();
}

bool World::isDaytime( void ) const noexcept
{
	if( mTick <= csDaytimeLengthInTicks )
	{
		return true;
	}
	return false;
}

bool World::isNighttime( void ) const noexcept
{
	if( mTick > csDaytimeLengthInTicks )
	{
		return true;
	}
	return false;
}

const uint16_t& World::getTick( void ) const noexcept
{
	return mTick;
}

void World::nextTick( void ) noexcept
{
	if( mTick >= csDayLengthInTicks )
	{
		mTick = 0;
	}
	else
	{
		mTick++;
	}
	return;
}
