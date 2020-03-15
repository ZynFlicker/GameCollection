#pragma once
#include "GameOption.h"

//游戏后选项类
class EndOption :public GameOption
{
private:
	virtual void _initOptions();//初始化选项的字符
	virtual GAMEMSG _optionCtrl(int option);//处理选项的switch
	virtual bool _msgCtrl(const GAMEMSG& g_msg);//处理选项的switch
public:
	EndOption() : GameOption() { if (options == nullptr) _initOptions(); }
	~EndOption() { if (options) _releaseOptions(); }
};


