#pragma once
#include "GameOption.h"

//游戏主控制选项界面类
class MainOption : public GameOption
{
private:
	virtual void _initOptions();//初始化选项的字符
	virtual GAMEMSG _optionCtrl(int option);//处理选项的switch
	virtual bool _msgCtrl(const GAMEMSG& g_msg);//处理选项的switch
public:
	MainOption() : GameOption() { if (options == nullptr) _initOptions(); }
	~MainOption() { if (options) _releaseOptions(); }
};

