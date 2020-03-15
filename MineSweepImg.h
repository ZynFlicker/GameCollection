#pragma once

#include "BlockImg.h"
class MineSweepImg : public BlockImg
{
private:
	static PIMAGE blank, normal, chosen, flag, flag_chosen, quote, quote_chosen, mine, flag_mine;
public:
	virtual PIMAGE getBlockImg(int blocktype);
	MineSweepImg();
	~MineSweepImg();
};



