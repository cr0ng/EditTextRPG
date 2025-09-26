#pragma once
#include <string>


class EquipmentBase 
{

protected:

	std::string Name;
	int Level; // ��ȭ ��� (0���� ����)
	int BaseStat; // �⺻ �ɷ�ġ

public:

	EquipmentBase(const std::string& name = "", int baseStat = 0)
		: Name(name), Level(0), BaseStat(baseStat) 
	{

	}

	virtual ~EquipmentBase() {}


	int GetLevel() const { return Level; }
	const std::string& GetName() const { return Name; }


	// ���� �ɷ�ġ: �⺻ + ���� ������
	int GetStat() const;


	// ��޺� ������(���� 1 �ø� �� ������ ��)
	virtual int GetIncrementPerLevel(int levelToReach) const = 0;


	// ��޺� ����Ȯ��(%)
	virtual int GetSuccessChance(int currentLevel) const = 0;


	// ��޺� �Ҹ� ���� ����
	virtual int GetOreCost(int currentLevel) const = 0;


	// ���� �� ���� ��
	void IncreaseLevel();

};