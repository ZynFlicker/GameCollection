#include "MineSweepOption.h"

//初始化选项的字符 
void MineSweepOption::_initOptions()
{
	options = new char* [n_option];
	options[0] = new char[9]{ "简    单" };
	options[1] = new char[9]{ "中    等" };
	options[2] = new char[9]{ "困    难" };
}

//处理选项的switch
GAMEMSG MineSweepOption::_optionCtrl(int option)
{
	switch (option)
	{
	case 1:return EASY;
	case 2:return MEDIUM;
	case 3:return HARD;
	}
}

//处理选项的switch
bool MineSweepOption::_msgCtrl(const GAMEMSG& g_msg)
{
	bool chosen = true;
	switch (g_msg)
	{
	case EASY:	 break;
	case MEDIUM: break;
	case HARD:	 break;
	default:chosen = false; break;
	}
	return chosen;
}