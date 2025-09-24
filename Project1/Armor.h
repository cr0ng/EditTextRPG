#pragma once
#include "EquipmentBase.h"

//방어구 전용 클래스
// 기본 방어력(BaseDefense)에 강화 단계 x DefensePerPlus 만큼 더해 최종 방어력

class Armor : public EquipmentBase
{
public:
	Armor(const std::string& inName, int inBaseDefense)
		: EquipmentBase(inName, 5), BaseDefense(inBaseDefense)
	{

	}

	int GetPower() const override { return BaseDefense + GetPlus() * DefensePerPlus; }

	static constexpr int DefensePerPlus = 3;

private:

	int BaseDefense = 1;	//	기본 방어력

};


