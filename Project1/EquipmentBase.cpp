#include "EquipmentBase.h"


int EquipmentBase::GetStat() const 
{
	int total = BaseStat;
	for (int lv = 1; lv <= Level; ++lv) 
	{
		total += GetIncrementPerLevel(lv);
	}
	return total;
}


void EquipmentBase::IncreaseLevel() 
{
	++Level;
}
