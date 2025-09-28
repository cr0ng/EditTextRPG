#pragma once
#include "Player.h"


class Home 
{

public:

	// 무기 강화 시도
	void EnhanceWeapon(Player& p, int randPercent, int Fortune);
	// 방어구 강화 시도
	void EnhanceArmor(Player& p, int randPercent, int Fortune);

};