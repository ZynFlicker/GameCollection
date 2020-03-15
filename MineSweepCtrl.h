#pragma once
#include"MineSweepResource.h"

#define MS_IMG_SIZE 35
//扫雷游戏控制类
class MineSweepCtrl :public BlockCtrl
{
private:
	int m_nums, m_left;
	MineSweepBlock** blocks;

	//各种资源加载
	virtual void _initEnd();		//结束窗口加载
	virtual void _deleteEnd();		//结束窗口释放
	virtual void _initOption();		//选项窗口加载
	virtual void _deleteOption();	//选项窗口释放
	virtual void _initImgs();
	virtual void _deleteImgs();
	virtual void _initBlocks();
	virtual void _deleteBlocks();
	virtual void _initCtrl();
	void _initMines(int x, int y);

	//棋盘绘制
	virtual void _drawBlocks();
	void _drawMines();

	//鼠标点击
	virtual void _clickCtrl(mouse_msg msg);

	//空白块展开
	void _selectBlank(int x, int y);

public:
	MineSweepCtrl() :BlockCtrl(9, 9), m_nums(10), m_left(m_nums){ _initBlocks(); }
	~MineSweepCtrl() { _deleteBlocks(); _deleteImgs(); }

	virtual GAMEMSG GamePlay();
	virtual GAMEMSG GameEnd(GAMEMSG msg);
	virtual GAMEMSG GameOption();
	virtual void GameReplay();
};

inline void MineSweepCtrl::_initEnd()
{
	if (endOption == nullptr)
		endOption = new EndOption();
}

inline void MineSweepCtrl::_deleteEnd()
{
	if (endOption)
	{
		delete endOption;
		endOption = nullptr;
	}

}

inline void MineSweepCtrl::_initOption()
{
	if (option == nullptr)
		option = new MineSweepOption();
}

inline void MineSweepCtrl::_deleteOption()
{
	if (option)
	{
		delete option;
		option = nullptr;
	}
}

inline void MineSweepCtrl::_initImgs()
{
	if (imgs == nullptr)
		imgs = new MineSweepImg();
}

inline void MineSweepCtrl::_deleteImgs()
{
	if (imgs)
	{
		delete imgs;
		imgs = nullptr;
	}
}

