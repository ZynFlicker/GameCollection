#pragma once
#include"BlockImg.h"
#include"EndOption.h"


//����Ƴ������
//��������Ŀ���Ǹ�ɨ����Ϸ���Ҿ������������̲��ֵ���Ϸ���½ӿںͲ���
//����úϼ�����չ
class BlockCtrl
{
protected:
	int rows, cols;//���̻�������
	GameOption* endOption;
	GameOption* option;
	BlockImg* imgs;

	//������Դ�ļ��غ��ͷ�
	virtual void _initEnd() = 0;
	virtual void _deleteEnd() = 0;
	virtual void _initOption() = 0;
	virtual void _deleteOption() = 0;
	virtual void _initImgs() = 0;
	virtual void _deleteImgs() = 0;
	virtual void _initBlocks() = 0;
	virtual void _deleteBlocks() = 0;
	virtual void _initCtrl() = 0;

	//���̻���
	virtual void _drawBlocks() = 0;

	//�����Ӧ
	virtual void _clickCtrl(mouse_msg msg) = 0;
public:
	BlockCtrl(int x, int y) : rows(x)
		, cols(y)
		, endOption(nullptr)
		, option(nullptr)
		, imgs(nullptr) {}

	//�����ͳһ�ӿ�
	virtual GAMEMSG GamePlay() = 0;
	virtual GAMEMSG GameEnd(GAMEMSG msg) = 0;
	virtual GAMEMSG GameOption() = 0;
	virtual void GameReplay() = 0;
};