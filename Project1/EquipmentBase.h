#pragma once
#include <string>

class EquipmentBase
{
public:

	EquipmentBase(const std::string& inName, int inMaxPlus)
		: Name(inName), MaxPlus(inMaxPlus)
	{

	}

	virtual ~EquipmentBase() = default;

	int GetPlus() const { return Plus; }
	void IncreasePlus() { if (Plus < MaxPlus) ++Plus; }
	void DecreasePlus() { if (Plus > 0) --Plus; }

	const std::string& GetName() const { return Name; }
	int GetMaxPlus() const { return MaxPlus; }

	virtual int GetPower() const = 0;

protected:

	std::string Name;
	int Plus;
	int MaxPlus;

};
