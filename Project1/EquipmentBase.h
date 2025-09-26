#pragma once
#include <string>


class EquipmentBase 
{

protected:

	std::string Name;
	int Level; // 강화 등급 (0부터 시작)
	int BaseStat; // 기본 능력치

public:

	EquipmentBase(const std::string& name = "", int baseStat = 0)
		: Name(name), Level(0), BaseStat(baseStat) 
	{

	}

	virtual ~EquipmentBase() {}


	int GetLevel() const { return Level; }
	const std::string& GetName() const { return Name; }


	// 현재 능력치: 기본 + 누적 증가량
	int GetStat() const;


	// 등급별 증가량(레벨 1 올릴 때 오르는 양)
	virtual int GetIncrementPerLevel(int levelToReach) const = 0;


	// 등급별 성공확률(%)
	virtual int GetSuccessChance(int currentLevel) const = 0;


	// 등급별 소모 광석 개수
	virtual int GetOreCost(int currentLevel) const = 0;


	// 성공 시 레벨 업
	void IncreaseLevel();

};