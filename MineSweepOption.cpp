#include "MineSweepOption.h"

//��ʼ��ѡ����ַ� 
void MineSweepOption::_initOptions()
{
	options = new char* [n_option];
	options[0] = new char[9]{ "��    ��" };
	options[1] = new char[9]{ "��    ��" };
	options[2] = new char[9]{ "��    ��" };
}

//����ѡ���switch
GAMEMSG MineSweepOption::_optionCtrl(int option)
{
	switch (option)
	{
	case 1:return EASY;
	case 2:return MEDIUM;
	case 3:return HARD;
	}
}

//����ѡ���switch
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