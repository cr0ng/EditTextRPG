
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
		printf("!!!!!   ������ �����մϴ�. �ʿ�: %d\n", cost);
		return;
	}

		printf("------------------------------------------------------\n");
		printf("��ȭ �õ�!   ���� %s +%d, Ȯ�� %d%%, �Ҹ� ���� %d��...\n",
		eq.GetName().c_str(), curLv, chance, cost);
		printf("------------------------------------------------------\n");

		if (Fortune == 1) {
			randPercent += 10;
			p.ConsumeFortune(1);
		}
	if (randPercent <= chance) 
	{
		eq.IncreaseLevel();
		printf(">>>>>>  ����!  <<<<<< %s�� ���� +%d �Դϴ�.\n", eq.GetName().c_str(), eq.GetLevel());
	}
	else 
	{
		printf(">>>>>>  ����...  <<<<<< ��� ��ȭ ����.\n");
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