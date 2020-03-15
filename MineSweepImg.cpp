#include "MineSweepImg.h"

PIMAGE MineSweepImg::blank = nullptr;
PIMAGE MineSweepImg::normal = nullptr;
PIMAGE MineSweepImg::chosen = nullptr;
PIMAGE MineSweepImg::flag = nullptr;
PIMAGE MineSweepImg::flag_chosen = nullptr;
PIMAGE MineSweepImg::quote = nullptr;
PIMAGE MineSweepImg::quote_chosen = nullptr;
PIMAGE MineSweepImg::mine = nullptr;
PIMAGE MineSweepImg::flag_mine = nullptr;
 
PIMAGE MineSweepImg::getBlockImg(int blocktype)
{
	switch (blocktype)
	{
	case 0: return blank; break;
	case 1: return normal; break;
	case 2: return chosen; break;
	case 3: return flag; break;
	case 4: return flag_chosen; break;
	case 5: return quote; break;
	case 6: return quote_chosen; break;
	case 7: return mine; break;
	case 8: return flag_mine; break;
	default:return nullptr; break;
	}
}

MineSweepImg::MineSweepImg()
{
	blank = newimage();
	normal = newimage();
	chosen = newimage();
	flag = newimage();
	flag_chosen = newimage();
	quote = newimage();
	quote_chosen = newimage();
	mine = newimage();
	flag_mine = newimage();
	getimage(blank, "MineSweepImg\\blank.bmp");
	getimage(normal, "MineSweepImg\\normal.bmp");
	getimage(chosen, "MineSweepImg\\chosen.bmp");
	getimage(flag, "MineSweepImg\\flag.bmp");
	getimage(flag_chosen, "MineSweepImg\\flag_chosen.bmp");
	getimage(quote, "MineSweepImg\\quote.bmp");
	getimage(quote_chosen, "MineSweepImg\\quote_chosen.bmp");
	getimage(mine, "MineSweepImg\\mine.bmp");
	getimage(flag_mine, "MineSweepImg\\flag_mine.bmp");
}

MineSweepImg::~MineSweepImg()
{
	delimage(blank);
	delimage(normal);
	delimage(chosen);
	delimage(flag);
	delimage(flag_chosen);
	delimage(quote);
	delimage(quote_chosen);
	delimage(mine);
	delimage(flag_mine);
}
