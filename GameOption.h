#pragma once
#include<graphics.h>
//��Ϸ��Ϣ��������Ҫ����Ϣ����
enum GAMEMSG 
{
	//������Ϣ
	PLAY, REPLAY, SET, QUIT, WIN, LOSE,
	
	//�Ѷ���Ϣ
	EASY, MEDIUM, HARD,
	
	//��Ϸѡ��
	MINESWEEP, EMPRESS, COMING
};

//ѡ�����
//���ǵ��������Ϸ�ϼ�������չ�Ļ����д�����ѡ��ڣ���˳������
class GameOption
{
protected:
	//����ѡ���ͨ�ó�Ա
	char** options;//ѡ���ַ�����
	int base_x, base_y;//��ͼ�Ļ�׼����
	int n_option;//ѡ�������
	virtual void _initOptions() = 0;//��ʼ��ѡ����ַ�
	virtual GAMEMSG _optionCtrl(int option) = 0;//����ѡ���switch
	virtual bool _msgCtrl(const GAMEMSG& g_msg) = 0;//����ѡ���switch
	void _releaseOptions();//�ͷ�ѡ���ַ�
	void _drawOptions();//���ƻ���
	void _mouseCtrl(mouse_msg msg, GAMEMSG& g_msg);//�����Ӧ
public:
	GameOption();
	GAMEMSG GameOptions();//ѡ����Ƶ�����ӿ�
};


inline GameOption::GameOption() :options(nullptr), n_option(3)
{
	int left, right, up, down;
	getviewport(&left, &up, &right, &down);
	base_x = (left + right) / 2 - 55;
	base_y = (up + down) / 2;
}