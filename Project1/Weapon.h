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
		// 레벨이 오를수록 증가량도 커짐
		return 2 + levelToReach; // 3,4,5,...
	}


	int GetSuccessChance(int currentLevel) const override 
	{
		// 0강 90%에서 시작, 레벨당 -10%, 최저 10%
		int chance = 90 - currentLevel * 10;
		if (chance < 10) chance = 10;
		return chance;
	}


	int GetOreCost(int currentLevel) const override 
	{
		// 시도시 소모 광석: 1 + 현재 레벨
		return 1 + currentLevel;
	}
};