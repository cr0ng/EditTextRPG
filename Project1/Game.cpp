#include "Game.h"
#include "EquipmentBase.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>

// ������ : srand(time(nullptr))���� ���� �õ� ����
Game::Game()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// ���� ���� ����
void Game::Run()
{
	while (true)
	{
		PrintMenu();
		int cmd = 0;
		std::cin >> cmd;
		if (!std::cin) 
		{
			std::cin.clear(); 
			std::cin.ignore(1000, 'n');  
			std::printf("\n[!] ���ڸ� �Է��ϼ���.\n\n");
			continue;
		}

		if (cmd == 1) DoHunt();
		else if (cmd == 2) DoEnhance();
		else if (cmd == 3) ShowStatus();
		else if (cmd == 4) FightBoss();
		else if (cmd == 0)
		{
			printf("\n������ �����մϴ�.\n");
			break;
		}
		else
		{
			printf("\n[!] �߸��� �����Դϴ�.\n\n");
		}
	}
}


void Game::PrintMenu()
{
	printf("=============================\n");
	printf("1) �Ĺ�(����/���)\n");
	printf("2) ��� ��ȭ(����/�� ����)\n");
	printf("3) ���� ����\n");
	printf("4) ���� ����\n");
	printf("0) ����\n");
	printf("���� : ");
	

}


void Game::DoHunt()
{
	int gotOre = RandInt(1, 3);
	int gotGold = RandInt(5, 15);
	Ores += gotOre;
	Gold += gotGold;
	printf("\n[�Ĺ� �Ϸ�] ���� +%d, ��� +%d (����: ���� %d, ��� %d\n\n", gotOre, gotGold, Ores, Gold);


}


void Game::ShowStatus()
{
}


void Game::DoEnhance()
{
}

void Game::FightBoss()
{
}

int Game::RandInt(int a, int b)
{
	return 0;
}
