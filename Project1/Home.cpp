
#include <stdio.h>
#include "Home.h"


static void TryEnhance(EquipmentBase& eq, Player& p, int randPercent) 
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


void Home::EnhanceWeapon(Player& p, int randPercent) 
{
	TryEnhance(p.Wpn, p, randPercent);
}


void Home::EnhanceArmor(Player& p, int randPercent) 
{
	TryEnhance(p.Arm, p, randPercent);
}