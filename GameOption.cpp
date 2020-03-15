#include "GameOption.h"
#define FONT_HEIGHT 20	//选项字体的高度
#define FONT_WIDTH 15	//选项字体的宽度，实际只是半个字的宽度

//释放选项字符
void GameOption::_releaseOptions()
{
	for (int i = 0; i < n_option; ++i)
		delete[]options[i];
	delete[]options;
}

//绘制画面
void GameOption::_drawOptions()
{
	cleardevice();
	setcolor(WHITE);
	setfont(40, 25, "宋体");
	outtextxy(base_x - 35, base_y - 80, "游戏选项");
	setfont(FONT_HEIGHT, FONT_WIDTH, "宋体");
	for (int i = 0; i < n_option; ++i)
	{
		outtextxy(base_x, base_y + i * FONT_HEIGHT * 2, options[i]);
	}
}

//鼠标事件响应的主体
void GameOption::_mouseCtrl(mouse_msg msg, GAMEMSG& g_msg)
{
	if (msg.x < base_x
		|| msg.x >= base_x + FONT_WIDTH * 4 * 2
		|| msg.y < base_y
		|| msg.y >= base_y + FONT_HEIGHT * (n_option * 2 - 1) / n_option * n_option)
		return;
	int option = (msg.y - base_y) / (FONT_HEIGHT * (n_option * 2 - 1) / n_option) + 1;
	if (msg.is_down())
	{
		g_msg = _optionCtrl(option);
	}
	if (msg.is_move())
	{
		_drawOptions();
		line(base_x
			, base_y + option * FONT_HEIGHT * 2 - FONT_HEIGHT
			, base_x + FONT_WIDTH * 4 * 2
			, base_y + option * FONT_HEIGHT * 2 - FONT_HEIGHT);
	}
}

//选项控制的主体
GAMEMSG GameOption::GameOptions()
{
	_drawOptions();
	GAMEMSG g_msg = PLAY;
	mouse_msg msg;
	for (; is_run(); delay_fps(60))
	{
		while (mousemsg())
		{
			msg = getmouse();
			_mouseCtrl(msg, g_msg);
			if (_msgCtrl(g_msg))
				return g_msg;
		}
	}
}