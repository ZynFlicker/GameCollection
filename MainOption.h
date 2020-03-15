#pragma once
#include "GameOption.h"

//��Ϸ������ѡ�������
class MainOption : public GameOption
{
private:
	virtual void _initOptions();//��ʼ��ѡ����ַ�
	virtual GAMEMSG _optionCtrl(int option);//����ѡ���switch
	virtual bool _msgCtrl(const GAMEMSG& g_msg);//����ѡ���switch
public:
	MainOption() : GameOption() { if (options == nullptr) _initOptions(); }
	~MainOption() { if (options) _releaseOptions(); }
};

