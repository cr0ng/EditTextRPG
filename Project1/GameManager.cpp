#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GameManager.h"


GameManager::GameManager()
	: player("��"),enemies{ Enemy("���̷���", 50, 7, 1), Enemy("�ɸ����ν�", 100, 13, 3), Enemy("�Ǹ���", 130, 20, 6) },
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
	printf("\n========= ���� =========================%s", "\n");
	printf("��: %d / ������������ ���� ��: %d\n", turn, (maxTurnsBeforeForcedBattle - (turn % maxTurnsBeforeForcedBattle)) % maxTurnsBeforeForcedBattle);
	printf("========================================\n");
	printf("HP: %d/%d | ATK: %d | DEF: %d | ����: %d | ��: %d\n",
		player.GetHP(), player.GetMaxHP(), player.GetAttack(), player.GetDefense(), player.GetOres(), player.GetFortune());
	printf("========================================\n");
	printf("���� %s +%d, �� %s +%d\n",
		player.Wpn.GetName().c_str(), player.Wpn.GetLevel(),
		player.Arm.GetName().c_str(), player.Arm.GetLevel());
	printf("========================================\n");
	printf("���� ��: %s (HP %d)\n", enemies[currentEnemyIdx].GetName().c_str(), enemies[currentEnemyIdx].GetHP());
	printf("========================================\n");
}


void GameManager::DoFarm() 
{
	// ���� ���: 0~3��
	int ores = std::rand() % 4;

	// ��ȭ Ȯ�� �÷��ִ� ������ 10% Ȯ���� ������
	int HaveFortune = std::rand() % 101;

	if (HaveFortune < 10) {
		player.AddFortune(1);
	}

	player.AddOres(ores);
	++turn;
	printf("========================================\n");
	printf("�Ĺ� �Ϸ�. ���� %d�� ȹ��! (�� %d)\n", ores, player.GetOres());
	if (HaveFortune < 10) {
		printf("����! ����� �� 1�� ȹ��! (�� %d)\n", player.GetFortune());
	}
}


void GameManager::DoEnhance()
{
	printf("========================================\n");
	printf("���� ��ȭ(1) / �� ��ȭ(2) ����: ");
	int sel = 0;
	std::cin >> sel;

	if (sel == 1) 
	{
		int curLv = player.Wpn.GetLevel();
		int chance = player.Wpn.GetSuccessChance(curLv);
		int cost = player.Wpn.GetOreCost(curLv);
		printf("========================================\n");
		printf("����: ���� +%d -> +%d �õ� | ����Ȯ�� %d%% | �Ҹ� ���� %d�� (���� %d) | �� (���� %d) \n",
			curLv, curLv + 1, chance, cost, player.GetOres(), player.GetFortune());
		printf("========================================\n");
		printf("��ȭ�Ͻðڽ��ϱ�? (1=��, 2=�ƴϿ�) > ");
		int confirm = 0;
		std::cin >> confirm;
		if (confirm != 1) 
		{
			printf("��ȭ�� ����߽��ϴ�.\n");
			return;
		}

		printf("���� ����Ͻðڽ��ϱ�? (1=��, 2=�ƴϿ�) > ");
		int ForturnConfirm = 0;
		std::cin >> ForturnConfirm;
		if (confirm == 1)
		{
			printf("���� ����Ͽ� ��ȭ Ȯ���� �÷Ƚ��ϴ�. \n");
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
		printf("����: �� +%d -> +%d �õ� | ����Ȯ�� %d%% | �Ҹ� ���� %d�� (���� %d) | �� (���� %d)\n",
			curLv, curLv + 1, chance, cost, player.GetOres(), player.GetFortune());
		printf("========================================\n");
		printf("��ȭ�Ͻðڽ��ϱ�? (1=��, 2=�ƴϿ�) > ");
		int confirm = 0;
		std::cin >> confirm;
		if (confirm != 1) 
		{
			printf("��ȭ�� ����߽��ϴ�.\n");
			return;
		}

		printf("���� ����Ͻðڽ��ϱ�? (1=��, 2=�ƴϿ�) > ");
		int ForturnConfirm = 0;
		std::cin >> ForturnConfirm;
		if (confirm == 1)
		{
			printf("���� ����Ͽ� ��ȭ Ȯ���� �÷Ƚ��ϴ�. \n");
			home.EnhanceArmor(player, RollPercent(), 1);
		}
		if (confirm == 2)
		{
			home.EnhanceArmor(player, RollPercent(), 0);
		}
	}
	else
	{
		printf("���\n");
		return;
	}

	++turn; 
}


bool GameManager::DoBattle() 
{
	Enemy& e = enemies[currentEnemyIdx];
	e.Reset();
	printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("���� ����! ��: %s\n", e.GetName().c_str());

	while (!player.IsDead() && !e.IsDead()) 
	{
		printf("++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		printf("\n�����Ϸ��� 1 �Է�: ");
		int cmd = 0;
		std::cin >> cmd;
		if (cmd != 1) continue;

		int dmgToEnemy = player.GetAttack() - e.GetDefense();
		if (dmgToEnemy < 1) dmgToEnemy = 1;
		e.TakeDamage(dmgToEnemy);
		printf("++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		printf("�� ����! %s���� %d ���� (���� ü��: %d)\n",
			e.GetName().c_str(), dmgToEnemy, e.GetHP());
		if (e.IsDead()) break;

		printf("++++++++++++++++++++++++++++++++++++++++++++++\n\n");
		printf("���� ����!\n");
		int dmgToPlayer = e.GetAttack() - player.GetDefense();
		if (dmgToPlayer < 1) dmgToPlayer = 1;
		player.TakeDamage(dmgToPlayer);
		
		printf("%s�� ����! %d ���� (�� ü��: %d/%d)\n",
			e.GetName().c_str(), dmgToPlayer, player.GetHP(), player.GetMaxHP());
	}

	if (player.IsDead()) 
	{
		printf("\n");
		printf("!!!!!    �й�...    !!!!! ���� ����\n");
		return false;                // ����
	}
	else 
	{
		printf("\n");
		printf("*****    �¸�!    *****\n");
		++currentEnemyIdx;
		if (currentEnemyIdx >= 3) 
		{
			printf("***********************************************\n\n");
			printf("������ ���� �����߷ȴ�! ���� Ŭ����!\n");
			printf("***********************************************\n\n");
			return false;            // ����
		}
		player.HealFull();
		return true;                 // ���
	}
}



void GameManager::Run() 
{
	bool running = true;
	while (running) 
	{
		//���� ���� ǥ��
		PrintStatus();

		// ���� ���� Ÿ�̹�
		if (turn > 0 && (turn % maxTurnsBeforeForcedBattle) == 0) 
		{
			printf("\n>>> ���� ���� �ߵ�! <<<\n");
			if (!DoBattle()) return; 
		}

		// ������ UI
		printf("\n������:   [1: �Ĺ�] [2: ��ȭ] [3: ����]          [4: ����]\n�Է�: ");
		int cmd = 0; std::cin >> cmd;
		if (cmd == 1) DoFarm();
		else if (cmd == 2) DoEnhance();
		else if (cmd == 3)
		{
			if(!DoBattle()) running = false;
		}
		else if (cmd == 4) { printf("����\n"); running = false; }
		else { printf("�߸��� �Է�\n"); }
	}
}