#pragma once

#include <cstdint>

using Block_t = uint16_t;

enum class BlockId : Block_t
{
	AIR,
	DIRT,
	GRASS,
	STONE,
	SAND,


	NUM_BLOCKS
};

enum class Facing : uint8_t
{
	UP,
	DOWN,
	NORTH,
	SOUTH,
	WEST,
	EAST
};