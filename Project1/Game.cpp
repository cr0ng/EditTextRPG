#include "Game.h"
#include "EquipmentBase.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <iostream>

// 생성자 : srand(time(nullptr))으로 난수 시드 설정
Game::Game()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// 게임 메인 루프
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
			std::printf("\n[!] 숫자를 입력하세요.\n\n");
			continue;
		}

		if (cmd == 1) DoHunt();
		else if (cmd == 2) DoEnhance();
		else if (cmd == 3) ShowStatus();
		else if (cmd == 4) FightBoss();
		else if (cmd == 0)
		{
			printf("\n게임을 종료합니다.\n");
			break;
		}
		else
		{
			printf("\n[!] 잘못된 선택입니다.\n\n");
		}
	}
}


void Game::PrintMenu()
{
	printf("=============================\n");
	printf("1) 파밍(광석/골드)\n");
	printf("2) 장비 강화(무기/방어구 선택)\n");
	printf("3) 상태 보기\n");
	printf("4) 보스 도전\n");
	printf("0) 종료\n");
	printf("선택 : ");
	

}


void Game::DoHunt()
{
	int gotOre = RandInt(1, 3);
	int gotGold = RandInt(5, 15);
	Ores += gotOre;
	Gold += gotGold;
	printf("\n[파밍 완료] 광석 +%d, 골드 +%d (보유: 광석 %d, 골드 %d\n\n", gotOre, gotGold, Ores, Gold);


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
