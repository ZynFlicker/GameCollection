#include "MainOption.h"

void MainOption::_initOptions()
{
	n_option = 4;
	options = new char* [n_option];
	options[0] = new char[9] {"ɨ    ��"};
	options[1] = new char[9] {"�ʺ���Ϸ"};
	options[2] = new char[9] {"�����ڴ�"};
	options[3] = new char[9] {"��    ��"};
}
 
GAMEMSG MainOption::_optionCtrl(int option)
{
	switch (option)
	{
	case 1:return MINESWEEP;
	case 2:return EMPRESS;
	case 3:return COMING;
	case 4:return QUIT;
	}
}

bool MainOption::_msgCtrl(const GAMEMSG& g_msg)
{
	bool chosen = true;
	switch (g_msg)
	{
	case MINESWEEP: break;
	case EMPRESS:	break;
	case COMING:	break;
	case QUIT:		break;
	default:chosen = false; break;
	}
	return chosen;
}
