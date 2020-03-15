#include"MineSweepCtrl.h"
#include"MineSweepBlock.h"
#include<ctime>
#include<cstdlib>
#include<stdio.h>

//游戏棋盘初始化
void MineSweepCtrl::_initCtrl()
{
	initgraph(rows * MS_IMG_SIZE, cols * MS_IMG_SIZE, INIT_RENDERMANUAL);
	HWND g_hwnd = getHWnd();
	SetWindowText(g_hwnd, "MineSweep —— by Flicker");
	_initImgs();
	_drawBlocks();
	setbkmode(TRANSPARENT);
	setcolor(RED);
	setfont(18, 10, "宋体");
	outtextrect(1, 1, rows * MS_IMG_SIZE, cols * MS_IMG_SIZE, "点击鼠标开始游戏\n空格键选择难度\n\tq键退出");
	setfont(MS_IMG_SIZE, MS_IMG_SIZE, "宋体");
	setcolor(BLACK);
}


//游戏主体
GAMEMSG MineSweepCtrl::GamePlay()
{
	_deleteOption();
	_deleteEnd();
	mouse_msg msg;
	_initCtrl();
	for (; is_run(); delay_fps(60))
	{
		while (kbhit())
		{
			char ch = getch();
			if (ch == 'q') return QUIT;
			else if (ch == ' ') return SET;
			else if (ch == 'r') return REPLAY;
		}
		msg = getmouse();
		if (msg.is_down())
			break;
	}
	for (; is_run(); delay_fps(60))
	{
		msg = getmouse();
		if (msg.is_left())
		{
			_drawBlocks();
			_initMines(msg.x / MS_IMG_SIZE, msg.y / MS_IMG_SIZE);
			break;
		}
	}
	for (; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			msg = getmouse();
			_clickCtrl(msg);
			if (m_left == -1)
			{
				_drawMines();
				return LOSE;
			}
			if (m_left == cols * rows)
				return WIN;
		}
	}
}

GAMEMSG MineSweepCtrl::GameEnd(GAMEMSG msg)
{
	int x = rows * MS_IMG_SIZE / 2 - 80;
	int y = cols * MS_IMG_SIZE / 2;
	setfont(40, 20, "宋体");
	setcolor(RED);
	switch (msg)
	{
	case WIN:	outtextxy(x, y - 50, "You Win!"); break;
	case LOSE:	outtextxy(x, y - 50, "You Lose!"); break;
	}
	setfont(15, 10, "宋体");
	outtextxy(x - 40, y + 50, "click anykey to continue!");
	mouse_msg m_msg;
	for (; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			m_msg = getmouse();
		}
		if (m_msg.is_down())
			break;
	}
	_initEnd();
	return endOption->GameOptions();
}

GAMEMSG MineSweepCtrl::GameOption()
{
	_deleteBlocks();
	_initOption();
	switch(option->GameOptions())
	{
	case EASY: 
		rows = cols = 9;
		m_nums = 10;
		break;
	case MEDIUM:
		rows = cols = 16;
		m_nums = 40;
		break;
	case HARD:
		rows = 30;
		cols = 16;
		m_nums = 99;
		break;
	}
	return REPLAY;
}

void MineSweepCtrl::GameReplay()
{
	cleardevice();
	_deleteBlocks();
	_initBlocks();
	m_left = m_nums;
}


//初始化模块数组
void MineSweepCtrl::_initBlocks()
{
	blocks = new MineSweepBlock*[rows];
	for (int i = 0; i < rows; ++i)
		blocks[i] = new MineSweepBlock[cols];
}

void MineSweepCtrl::_deleteBlocks()
{
	if (blocks)
	{
		for (int i = 0; i < rows; ++i)
			delete[] blocks[i];
		delete[] blocks;
	}
	blocks = nullptr;
}


//方向向量，方便向各个方向遍历
static int vx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
static int vy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };


//设置地雷，保证第一次点击不是地雷
void MineSweepCtrl::_initMines(int x, int y)
{
	srand((unsigned)time(0));
	int firstclick = x * cols + y;
	int blocknums = rows * cols;
	int set = m_nums;
	for (int i = 0; i < blocknums && set > 0; ++i)
	{
		if ((rand() % (blocknums - i) < set) && i != firstclick)
		{
			int mx = i / cols;
			int my = i % cols;
			blocks[mx][my].setMine();
			--set;
			int nx, ny;
			for (int k = 0; k < 8; ++k)
			{
				nx = mx + vx[k];
				ny = my + vy[k];
				if (nx < 0 || nx >= rows || ny < 0 || ny >= cols)
					continue;
				blocks[nx][ny].addFound();
			}
		}
	}
}


//绘制当前状态
void MineSweepCtrl::_drawBlocks()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			MSBType face = blocks[i][j].getFace();
			putimage(i * MS_IMG_SIZE, j * MS_IMG_SIZE, imgs->getBlockImg(face));
			if (face == BLANK && blocks[i][j].getFound() > 0)
			{
				int nums = blocks[i][j].getFound();
				char outnum[4];
				sprintf(outnum, "%d", nums);
				outtextxy(i * MS_IMG_SIZE, j * MS_IMG_SIZE, outnum);
			}
		}
	}
}


//地雷展开
void MineSweepCtrl::_drawMines()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if(blocks[i][j].isMine())
				putimage(i * MS_IMG_SIZE, j * MS_IMG_SIZE, imgs->getBlockImg(MINE));
		}
	}
}


//空白块的展开
void MineSweepCtrl::_selectBlank(int x, int y)
{
	for (int i = 0; i < 8; ++i)
	{
		int nx = x + vx[i];
		int ny = y + vy[i];
		if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || blocks[nx][ny].isMine())
			continue;
		if (blocks[nx][ny].getFace() != BLANK)
		{
			++m_left;
			blocks[nx][ny].setFace(BLANK);
			if (blocks[nx][ny].getFound() == 0)
				_selectBlank(nx, ny);
		}
	}
}


//鼠标事件控制
void MineSweepCtrl::_clickCtrl(mouse_msg msg)
{
	if (msg.x < 0 || msg.x >= rows * MS_IMG_SIZE || msg.y < 0 || msg.y >= cols * MS_IMG_SIZE)
		return;
	int x = msg.x / MS_IMG_SIZE;
	int y = msg.y / MS_IMG_SIZE;
	MSBType face = blocks[x][y].getFace();
	bool onlymove = false;
	if (msg.is_down())
	{
		if (msg.is_left())
		{
			if (blocks[x][y].getFace() == NORMAL)
			{
				if (blocks[x][y].isMine())
				{
					m_left = -1;
					blocks[x][y].setFace(MINE);
				}
				else
				{
					blocks[x][y].setFace(BLANK);
					++m_left;
					if(blocks[x][y].getFound() == 0)
						_selectBlank(x, y);
				}

			}
		}
		if (msg.is_right())
		{
			switch (face)
			{
			case NORMAL: blocks[x][y].setFace(FLAG); break;
			case FLAG:	 blocks[x][y].setFace(QUOTE); break;
			case QUOTE:	 blocks[x][y].setFace(NORMAL); break;
			}
		}
	}
	if(msg.is_move())
	{
		onlymove = true;
		switch (face)
		{
		case NORMAL: face = CHOSEN; break;
		case FLAG:	 face = FLAG_CHOSEN; break;
		case QUOTE:  face = QUOTE_CHOSEN; break;
		default:	 onlymove = false; break;
		}
	}
	_drawBlocks();
	if(onlymove)
		putimage(x * MS_IMG_SIZE, y * MS_IMG_SIZE, imgs->getBlockImg(face));
}

