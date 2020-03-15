#pragma once
#include"BlockImg.h"
#include"EndOption.h"


//块控制抽象基类
//抽象该类的目的是给扫雷游戏等我觉得类似于棋盘布局的游戏留下接口和参照
//方便该合集的扩展
class BlockCtrl
{
protected:
	int rows, cols;//棋盘基本参数
	GameOption* endOption;
	GameOption* option;
	BlockImg* imgs;

	//各种资源的加载和释放
	virtual void _initEnd() = 0;
	virtual void _deleteEnd() = 0;
	virtual void _initOption() = 0;
	virtual void _deleteOption() = 0;
	virtual void _initImgs() = 0;
	virtual void _deleteImgs() = 0;
	virtual void _initBlocks() = 0;
	virtual void _deleteBlocks() = 0;
	virtual void _initCtrl() = 0;

	//棋盘绘制
	virtual void _drawBlocks() = 0;

	//鼠标响应
	virtual void _clickCtrl(mouse_msg msg) = 0;
public:
	BlockCtrl(int x, int y) : rows(x)
		, cols(y)
		, endOption(nullptr)
		, option(nullptr)
		, imgs(nullptr) {}

	//抽象出统一接口
	virtual GAMEMSG GamePlay() = 0;
	virtual GAMEMSG GameEnd(GAMEMSG msg) = 0;
	virtual GAMEMSG GameOption() = 0;
	virtual void GameReplay() = 0;
};