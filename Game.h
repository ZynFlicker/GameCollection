#pragma once
#include"GameResource.h"
#include"MainOption.h"

//��Ϸ��������
class Game
{
private:
	BlockCtrl* game;
	GameOption* mainOption;
	void GamePlay();
	void GameEnd(GAMEMSG msg);
	void GameOption();
	void GameQuit();
	void GameReplay();
public:
	Game() : game(nullptr), mainOption(nullptr) {}
	void GameSelect();
};