#pragma once

#include "BlockID.h"
#include <array>


class Block
{
public:
	Block() = default;
	Block(BlockId id);
	Block(BlockId id, const std::string& texName);
	Block(	BlockId id, const std::string& texNameF, const std::string& texNameB,
			const std::string& texNameL, const std::string& texNameR, const std::string& texNameU, 
			const std::string& texNameD);
	BlockId id;

	bool operator ==(Block other) const
	{
		return id == other.id;
	}
	bool operator !=(Block other) const
	{
		return id != other.id;
	}

	std::string getTextureName(Facing dir);
private:
	//std::array<std::string, 6> tex;

	/*
	Properties:
	float hardness;	//In seconds to break
	Effective Tool
	*/
};

