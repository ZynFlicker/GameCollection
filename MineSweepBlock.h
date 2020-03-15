#pragma once
#include "Block.h"


//ɨ�׿����ʾ����
enum MSBType { BLANK, NORMAL, CHOSEN, FLAG, FLAG_CHOSEN, QUOTE, QUOTE_CHOSEN, MINE, FLAG_MINE };

//ɨ�׿���
class MineSweepBlock : public Block
{
private:
	MSBType face;
	bool mine;
	int found;
public:
	MineSweepBlock() :face(NORMAL), mine(false), found(0) {}
	void addFound() { ++found; }
	bool isMine() { return mine; }
	void setMine() { mine = true; }
	int getFound() { return found; }
	MSBType getFace() { return face; }
	void setFace(MSBType nface) { face = nface; }
};