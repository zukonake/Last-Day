#ifndef WORLDGENERATOR_HPP
#define WORLDGENERATOR_HPP

#include <world/world.hpp>

class WorldGenerator
{
public:
	enum worldGeneratorType;
	World generate( worldGeneratorType type );
	WorldGenerator();
};

#endif
