#pragma once
#include "Player.h"

// - 게임 전체 진행 담당
// - 메뉴 출력, 입력 처리, 파밍, 강화, 상태 보기, 보스전

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
