#pragma once
#include <string>


class Enemy 
{

	std::string Name;
	int MaxHP;
	int HP;
	int ATK;
	int DEF;

public:

	Enemy(const std::string& name = "Enemy", int hp = 20, int atk = 5, int def = 0)
		: Name(name), MaxHP(hp), HP(hp), ATK(atk), DEF(def)
	{

	}


	const std::string& GetName() const { return Name; }
	int GetHP() const { return HP; }


	void Reset() { HP = MaxHP; }


	int GetAttack() const { return ATK; }
	int GetDefense() const { return DEF; }


	bool IsDead() const { return HP <= 0; }


	void TakeDamage(int dmg) 
	{
		if (dmg < 0) dmg = 0;
		HP -= dmg;
		if (HP < 0) HP = 0;
	}
};