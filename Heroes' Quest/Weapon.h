#include "Object.h"
#include <vector>
#include <string>
#include <iostream>

#pragma once
class Weapon : public Object {

public:
	std::vector<std::string> enchantments;
	Weapon();	//	can make the constructor virtual
	Weapon(std::string type);

private:
	void enchant();
	void upgradeWeapon();
	std::string WeaponType;

};
