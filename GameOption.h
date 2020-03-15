#pragma once
#include<graphics.h>
//游戏信息传递所需要的消息类型
enum GAMEMSG 
{
	//基本消息
	PLAY, REPLAY, SET, QUIT, WIN, LOSE,
	
	//难度消息
	EASY, MEDIUM, HARD,
	
	//游戏选择
	MINESWEEP, EMPRESS, COMING
};

//选项窗口类
//考虑到对这个游戏合集进行扩展的话会有大量的选项窗口，因此抽象该类
class GameOption
{
protected:
	//所有选项窗口通用成员
	char** options;//选项字符串组
	int base_x, base_y;//绘图的基准坐标
	int n_option;//选项的数量
	virtual void _initOptions() = 0;//初始化选项的字符
	virtual GAMEMSG _optionCtrl(int option) = 0;//处理选项的switch
	virtual bool _msgCtrl(const GAMEMSG& g_msg) = 0;//处理选项的switch
	void _releaseOptions();//释放选项字符
	void _drawOptions();//绘制画面
	void _mouseCtrl(mouse_msg msg, GAMEMSG& g_msg);//鼠标响应
public:
	GameOption();
	GAMEMSG GameOptions();//选项控制的主体接口
};


inline GameOption::GameOption() :options(nullptr), n_option(3)
{
	int left, right, up, down;
	getviewport(&left, &up, &right, &down);
	base_x = (left + right) / 2 - 55;
	base_y = (up + down) / 2;
}