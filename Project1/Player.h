#pragma once
#include "Weapon.h"
#include "Armor.h"


class Player
{
public:

	Player();

	int GetBaseHP() { return BaseHP; }
	int GetBaseATK() { return BaseATK; }

	Weapon& GetWeapon() { return Sword; }
	Armor& GetArmor() { return Mail; }

	int GetAttack() { return Sword.GetPower(); }
	int GetDefense() { return Mail.GetPower(); }




private:
	int BaseHP = 100;
	int BaseATK = 10;

	Weapon Sword{ "Rusty Sword", 3 };
	Armor Mail{ "Worn Mail", 1 };

};