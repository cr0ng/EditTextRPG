#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Home.h"


class GameManager 
{
	Player player;
	Enemy enemies[3];
	int currentEnemyIdx;
	int turn;
	int maxTurnsBeforeForcedBattle; // 강제전투까지 턴 제한
	Home home;

public:

	GameManager();
	void Run();

private:

	void PrintStatus();
	void DoFarm();
	void DoEnhance();
	bool DoBattle();
	int RollPercent();
};