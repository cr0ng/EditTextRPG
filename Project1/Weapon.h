#pragma once
#include "EquipmentBase.h"


class Weapon : public EquipmentBase 
{

public:

	Weapon(const std::string& name = "Weapon", int baseStat = 5)
		: EquipmentBase(name, baseStat) 
	{

	}


	int GetIncrementPerLevel(int levelToReach) const override
	{
		// ������ �������� �������� Ŀ��
		return 2 + levelToReach; // 3,4,5,...
	}


	int GetSuccessChance(int currentLevel) const override 
	{
		// 0�� 90%���� ����, ������ -10%, ���� 10%
		int chance = 90 - currentLevel * 10;
		if (chance < 10) chance = 10;
		return chance;
	}


	int GetOreCost(int currentLevel) const override 
	{
		// �õ��� �Ҹ� ����: 1 + ���� ����
		return 1 + currentLevel;
	}
};