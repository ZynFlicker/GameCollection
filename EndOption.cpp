#include "EndOption.h"

//初始化选项
void EndOption::_initOptions()
{
	options = new char* [n_option];
	options[0] = new char[9]{ "重新开始" };
	options[1] = new char[9]{ "设    置" };
	options[2] = new char[9]{ "退    出" };
}


GAMEMSG EndOption::_optionCtrl(int option)
{
	switch (option)
	{
	case 1:return REPLAY;
	case 2:return SET;
	case 3:return QUIT;
	}
}

bool EndOption::_msgCtrl(const GAMEMSG& g_msg)
{
	bool chosen = true;
	switch (g_msg)
	{
	case REPLAY:break;
	case SET:	break;
	case QUIT:	break;
	default:	chosen = false; break;
	}
	return chosen;
}