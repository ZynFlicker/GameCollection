#pragma once
#include "GameOption.h"
class EndOption :public GameOption
{
private:
	virtual void _initOptions();//��ʼ��ѡ����ַ�
	virtual GAMEMSG _optionCtrl(int option);//����ѡ���switch
	virtual bool _msgCtrl(const GAMEMSG& g_msg);//����ѡ���switch
public:
	EndOption() : GameOption() { if (options == nullptr) _initOptions(); }
	~EndOption() { if (options) _releaseOptions(); }
};


