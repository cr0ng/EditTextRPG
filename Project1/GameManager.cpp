#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameManager.h"


GameManager::GameManager()
	: player("나"),enemies{ Enemy("스켈레톤", 50, 7, 1), Enemy("케르베로스", 100, 13, 3), Enemy("악마왕", 130, 20, 6) },
	currentEnemyIdx(0), turn(0), maxTurnsBeforeForcedBattle(6)
{
	std::srand((unsigned)std::time(nullptr));
}


int GameManager::RollPercent() 
{
	return (std::rand() % 100) + 1;
}


void GameManager::GetFortuneItem()
{
	

}


void GameManager::PrintStatus() 
{
	printf("\n========= 상태 =========================%s", "\n");
	printf("턴: %d / 강제전투까지 남은 턴: %d\n", turn, (maxTurnsBeforeForcedBattle - (turn % maxTurnsBeforeForcedBattle)) % maxTurnsBeforeForcedBattle);
	printf("========================================\n");
	printf("HP: %d/%d | ATK: %d | DEF: %d | 광석: %d | 행운석: %d\n",
		player.GetHP(), player.GetMaxHP(), player.GetAttack(), player.GetDefense(), player.GetOres(), player.GetFortune());
	printf("========================================\n");
	printf("무기 %s +%d, 방어구 %s +%d\n",
		player.Wpn.GetName().c_str(), player.Wpn.GetLevel(),
		player.Arm.GetName().c_str(), player.Arm.GetLevel());
	printf("========================================\n");
	printf("다음 적: %s (HP %d)\n", enemies[currentEnemyIdx].GetName().c_str(), enemies[currentEnemyIdx].GetHP());
	printf("========================================\n");
}


void GameManager::DoFarm() 
{
	// 랜덤 드랍: 0~3개
	int ores = std::rand() % 4;

	// 강화 확률 올려주는 아이템 10% 확률로 나오기
	int HaveFortune = std::rand() % 101;

	if (HaveFortune < 10) {
		player.AddFortune(1);
	}

	player.AddOres(ores);
	++turn;
	printf("========================================\n");
	printf("파밍 완료. 광석 %d개 획득! (총 %d)\n", ores, player.GetOres());
	if (HaveFortune < 10) {
		printf("축하! 행운의 돌 1개 획득! (총 %d)\n", player.GetFortune());
	}
}


void GameManager::DoEnhance()
{
	printf("========================================\n");
	printf("무기 강화(1) / 방어구 강화(2) 선택: ");
	int sel = 0;
	std::cin >> sel;

	if (sel == 1) 
	{
		int curLv = player.Wpn.GetLevel();
		int chance = player.Wpn.GetSuccessChance(curLv);
		int cost = player.Wpn.GetOreCost(curLv);
		printf("========================================\n");
		printf("예상: 무기 +%d -> +%d 시도 | 성공확률 %d%% | 소모 광석 %d개 (보유 %d) | 행운석 (보유 %d) \n",
			curLv, curLv + 1, chance, cost, player.GetOres(), player.GetFortune());
		printf("========================================\n");
		printf("강화하시겠습니까? (1=예, 2=아니오) > ");
		int confirm = 0;
		std::cin >> confirm;
		if (confirm != 1) 
		{
			printf("강화를 취소했습니다.\n");
			return;
		}

		printf("행운석을 사용하시겠습니까? (1=예, 2=아니오) > ");
		int ForturnConfirm = 0;
		std::cin >> ForturnConfirm;
		if (confirm == 1)
		{
			printf("행운석을 사용하여 강화 확률을 올렸습니다. \n");
			home.EnhanceWeapon(player, RollPercent(),1);
		}
		if (confirm == 2)
		{
			home.EnhanceWeapon(player, RollPercent(),0);
		}
	}
	else if (sel == 2) 
	{
		int curLv = player.Arm.GetLevel();
		int chance = player.Arm.GetSuccessChance(curLv);
		int cost = player.Arm.GetOreCost(curLv);
		printf("========================================\n");
		printf("예상: 방어구 +%d -> +%d 시도 | 성공확률 %d%% | 소모 광석 %d개 (보유 %d) | 행운석 (보유 %d)\n",
			curLv, curLv + 1, chance, cost, player.GetOres(), player.GetFortune());
		printf("========================================\n");
		printf("강화하시겠습니까? (1=예, 2=아니오) > ");
		int confirm = 0;
		std::cin >> confirm;
		if (confirm != 1) 
		{
			printf("강화를 취소했습니다.\n");
			return;
		}

		printf("행운석을 사용하시겠습니까? (1=예, 2=아니오) > ");
		int ForturnConfirm = 0;
		std::cin >> ForturnConfirm;
		if (confirm == 1)
		{
			printf("행운석을 사용하여 강화 확률을 올렸습니다. \n");
			home.EnhanceArmor(player, RollPercent(), 1);
		}
		if (confirm == 2)
		{
			home.EnhanceArmor(player, RollPercent(), 0);
		}
	}
	else
	{
		printf("취소\n");
		return;
	}

	++turn; 
}


bool GameManager::DoBattle() 
{
	Enemy& e = enemies[currentEnemyIdx];
	e.Reset();
	printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("전투 시작! 적: %s\n", e.GetName().c_str());

	while (!player.IsDead() && !e.IsDead()) 
	{
		printf("++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		printf("\n공격하려면 1 입력: ");
		int cmd = 0;
		std::cin >> cmd;
		if (cmd != 1) continue;

		int dmgToEnemy = player.GetAttack() - e.GetDefense();
		if (dmgToEnemy < 1) dmgToEnemy = 1;
		e.TakeDamage(dmgToEnemy);
		printf("++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		printf("내 공격! %s에게 %d 피해 (적의 체력: %d)\n",
			e.GetName().c_str(), dmgToEnemy, e.GetHP());
		if (e.IsDead()) break;

		printf("++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		printf("적의 공격!\n");
		int dmgToPlayer = e.GetAttack() - player.GetDefense();
		if (dmgToPlayer < 1) dmgToPlayer = 1;
		player.TakeDamage(dmgToPlayer);
		
		printf("%s의 공격! %d 피해 (내 체력: %d/%d)\n",
			e.GetName().c_str(), dmgToPlayer, player.GetHP(), player.GetMaxHP());
	}

	if (player.IsDead()) 
	{
		printf("\n");
		printf("!!!!!    패배...    !!!!! 게임 오버\n");
		return false;                // 종료
	}
	else 
	{
		printf("\n");
		printf("*****    승리!    *****\n");
		++currentEnemyIdx;
		if (currentEnemyIdx >= 3) 
		{
			printf("***********************************************\n\n");
			printf("마지막 적을 쓰러뜨렸다! 게임 클리어!\n");
			printf("***********************************************\n\n");
			return false;            // 종료
		}
		player.HealFull();
		return true;                 // 계속
	}
}



void GameManager::Run() 
{
	bool running = true;
	while (running) 
	{
		//현재 상태 표시
		PrintStatus();

		// 강제 전투 타이밍
		if (turn > 0 && (turn % maxTurnsBeforeForcedBattle) == 0) 
		{
			printf("\n>>> 강제 전투 발동! <<<\n");
			if (!DoBattle()) return; 
		}

		// 선택지 UI
		printf("\n선택지:   [1: 파밍] [2: 강화] [3: 전투]          [4: 종료]\n입력: ");
		int cmd = 0; std::cin >> cmd;
		if (cmd == 1) DoFarm();
		else if (cmd == 2) DoEnhance();
		else if (cmd == 3)
		{
			if(!DoBattle()) running = false;
		}
		else if (cmd == 4) { printf("종료\n"); running = false; }
		else { printf("잘못된 입력\n"); }
	}
}