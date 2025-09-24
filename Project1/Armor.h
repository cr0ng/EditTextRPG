#pragma once
#include "EquipmentBase.h"

//�� ���� Ŭ����
// �⺻ ����(BaseDefense)�� ��ȭ �ܰ� x DefensePerPlus ��ŭ ���� ���� ����

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

	int BaseDefense = 1;	//	�⺻ ����

};


