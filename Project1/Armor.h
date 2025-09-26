#pragma once
#include "EquipmentBase.h"


class Armor : public EquipmentBase
{

public:

	Armor(const std::string& name = "Armor", int baseStat = 3)
		: EquipmentBase(name, baseStat) 
	{

	}


	int GetIncrementPerLevel(int levelToReach) const override
	{
		// ���� ���� �� �������� ������ �������� ����
		return 1 + levelToReach; // 2,3,4,...
	}


	int GetSuccessChance(int currentLevel) const override 
	{
		int chance = 92 - currentLevel * 9; // ���� �� �� ����
		if (chance < 12) chance = 12;
		return chance;
	}


	int GetOreCost(int currentLevel) const override 
	{
		return 1 + currentLevel; // ���� ��Ģ
	}
};