#pragma once
#include "GameOption.h"

//ɨ����Ϸѡ����
class MineSweepOption : public GameOption
{
private:
	virtual void _initOptions();//��ʼ��ѡ����ַ�
	virtual GAMEMSG _optionCtrl(int option);//����ѡ���switch
	virtual bool _msgCtrl(const GAMEMSG& g_msg);//����ѡ���switch
public:
	MineSweepOption() : GameOption() { if (options == nullptr) _initOptions(); }
	~MineSweepOption(){ if (options) _releaseOptions(); }
};

