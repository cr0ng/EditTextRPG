#pragma once
#include <string>
#include "Weapon.h"
#include "Armor.h"


class Player
{
	std::string Name;
	int MaxHP;
	int HP;
	int BaseATK;
	int BaseDEF;
	int Ores; // ±¤¼®

public:

	Weapon Wpn;
	Armor Arm;


	Player(const std::string& name = "Me")
		: Name(name), MaxHP(100), HP(100), BaseATK(5), BaseDEF(2), Ores(0),
		Wpn("°Ë", 5), Arm("°©¿Ê", 2) 
	{

	}


	int GetHP() const { return HP; }
	int GetMaxHP() const { return MaxHP; }
	int GetOres() const { return Ores; }


	void HealFull() { HP = MaxHP; }


	void AddOres(int n) { Ores += n; }
	bool ConsumeOres(int n) 
	{
		if (Ores < n) return false;
		Ores -= n;
		return true;
	}


	int GetAttack() const { return BaseATK + Wpn.GetStat(); }
	int GetDefense() const { return BaseDEF + Arm.GetStat(); }


	bool IsDead() const { return HP <= 0; }


	void TakeDamage(int dmg)
	{
		if (dmg < 0) dmg = 0;
		HP -= dmg;
		if (HP < 0) HP = 0;
	}
};