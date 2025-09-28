
#include <stdio.h>
#include "Home.h"


static void TryEnhance(EquipmentBase& eq, Player& p, int randPercent, int Fortune) 
{

	int curLv = eq.GetLevel();
	int cost = eq.GetOreCost(curLv);
	int chance = eq.GetSuccessChance(curLv);

	if (!p.ConsumeOres(cost)) 
	{
		printf("------------------------------------------------------\n");
		printf("!!!!!   광석이 부족합니다. 필요: %d\n", cost);
		return;
	}

		printf("------------------------------------------------------\n");
		printf("강화 시도!   현재 %s +%d, 확률 %d%%, 소모 광석 %d개...\n",
		eq.GetName().c_str(), curLv, chance, cost);
		printf("------------------------------------------------------\n");

		if (Fortune == 1) {
			randPercent += 10;
			p.ConsumeFortune(1);
		}
	if (randPercent <= chance) 
	{
		eq.IncreaseLevel();
		printf(">>>>>>  성공!  <<<<<< %s은 이제 +%d 입니다.\n", eq.GetName().c_str(), eq.GetLevel());
	}
	else 
	{
		printf(">>>>>>  실패...  <<<<<< 등급 변화 없음.\n");
	}
}


void Home::EnhanceWeapon(Player& p, int randPercent, int Fortune) 
{
	TryEnhance(p.Wpn, p, randPercent, Fortune);
}



void Home::EnhanceArmor(Player& p, int randPercent, int Fortune)
{
	TryEnhance(p.Arm, p, randPercent, Fortune);
}