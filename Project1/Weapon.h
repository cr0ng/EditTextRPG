#pragma once
#include "EquipmentBase.h"

class Weapon : public EquipmentBase
{
public:

	Weapon(const std::string& inName, int inBaseDamage)
		: EquipmentBase(inName, 5), BaseDamage(inBaseDamage)
	{

	}

	int GetPower() const override { return BaseDamage + GetPlus() * DamagePerPlus; }

	static constexpr int DamagePerPlus = 4;

private:

	int BaseDamage = 3;
};

