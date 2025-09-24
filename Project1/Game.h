#pragma once
#include "Player.h"

// - ���� ��ü ���� ���
// - �޴� ���, �Է� ó��, �Ĺ�, ��ȭ, ���� ����, ������

class Game
{
public:
	Game();
	void Run();

private:

	void PrintMenu();
	void DoHunt();
	void DoEnhance();
	void ShowStatus();
	void FightBoss();

	int RandInt(int a, int b);


private:
	Player p;
	int Ores = 0;
	int Gold = 0;

};
