#include "Block.h"
//#include <bitset>

/*Block::Block(BlockId id)	:	id(id)
{

}

BlockDataCompressed Block::compress()
{
	union
	{
		BlockDataCompressed block;
		unsigned int intBlock;
	};
	//BlockDataCompressed block;
	block.ID = id;
	uint8_t X = static_cast<uint8_t>(pos.x) * 16;
	uint8_t Y = static_cast<uint8_t>(pos.y)	* 16;
	uint8_t Z = static_cast<uint8_t>(pos.z);
	uint8_t XZ = X + Z;
	uint8_t Y_Facing = Y + static_cast<uint8_t>(dir);

	block.XZ = XZ;
	block.Y_Facing = Y_Facing;

	//globalTemp = intBlock;

	return block;
}*/

Block::Block(BlockId id)	:	id(id)
{

}

Block::Block(BlockId id, const std::string & texName) : id(id)
{
	//tex.fill(texName);
}

Block::Block(BlockId id, const std::string & texNameF, const std::string & texNameB,
			const std::string & texNameL, const std::string & texNameR, const std::string & texNameU, 
			const std::string & texNameD) : id(id)
{
	/*tex[0] = texNameU;
	tex[1] = texNameD;
	tex[2] = texNameF;
	tex[3] = texNameB;
	tex[4] = texNameL;
	tex[5] = texNameR;*/
}

std::string Block::getTextureName(Facing dir)
{
	switch (dir)
	{
	case Facing::UP:
		return std::string("grass_top");//tex[0];
	case Facing::DOWN:
		return std::string("dirt");//tex[1];
	case Facing::NORTH:
		return std::string("grass_side");//tex[2];
	case Facing::SOUTH:
		return std::string("grass_side");// tex[3];
	case Facing::WEST:
		return std::string("grass_side");// tex[4];
	case Facing::EAST:
		return std::string("grass_side");// tex[5];
	}
	return std::string("filler");
}
