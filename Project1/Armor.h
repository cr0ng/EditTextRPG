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
		// 방어구는 조금 덜 오르지만 레벨이 오를수록 증가
		return 1 + levelToReach; // 2,3,4,...
	}


	int GetSuccessChance(int currentLevel) const override 
	{
		int chance = 92 - currentLevel * 9; // 조금 더 잘 붙음
		if (chance < 12) chance = 12;
		return chance;
	}


	int GetOreCost(int currentLevel) const override 
	{
		return 1 + currentLevel; // 동일 규칙
	}
};