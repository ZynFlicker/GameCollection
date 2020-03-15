#pragma once
#include "GameOption.h"
class MineSweepOption : public GameOption
{
private:
	virtual void _initOptions();//初始化选项的字符
	virtual GAMEMSG _optionCtrl(int option);//处理选项的switch
	virtual bool _msgCtrl(const GAMEMSG& g_msg);//处理选项的switch
public:
	MineSweepOption() : GameOption() { if (options == nullptr) _initOptions(); }
	~MineSweepOption(){ if (options) _releaseOptions(); }
};

