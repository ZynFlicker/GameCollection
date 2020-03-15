#include "Game.h"

void Game::GameSelect()
{
	initgraph(500, 500, INIT_RENDERMANUAL);
	HWND g_hwnd = getHWnd();
	SetWindowText(g_hwnd, "GameCollection ¡ª¡ª by Flicker");
	if (mainOption == nullptr)
	{
		mainOption = new MainOption();
	}
	while (game == nullptr)
	{
		switch (mainOption->GameOptions())
		{
		case MINESWEEP: game = new MineSweepCtrl(); break;
		//case EMPRESS: game = new EmpressCtrl(); break;
		case QUIT: 
			closegraph();
			if (mainOption)
			{
				delete mainOption;
			}
			return;
		default:break;
		}
	}
	GamePlay();
}


void Game::GamePlay()
{
	switch (game->GamePlay())
	{
	case REPLAY: GameReplay(); break;
	case WIN: GameEnd(WIN); break;
	case LOSE: GameEnd(LOSE); break;
	case SET: GameOption(); break;
	case QUIT: GameQuit(); break;
	}
}


void Game::GameEnd(GAMEMSG msg)
{
	switch (game->GameEnd(msg))
	{
	case REPLAY: GameReplay(); break;
	case QUIT: GameQuit(); break;
	case SET: GameOption(); break;
	}
}

void Game::GameOption()
{
	game->GameOption();
	GameReplay();
}

void Game::GameQuit()
{
	closegraph();
	delete game;
	game = nullptr;
	GameSelect();
}

void Game::GameReplay()
{
	game->GameReplay();
	GamePlay();
}

