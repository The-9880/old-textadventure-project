#include <string>

#pragma once
class Object
{

protected:
	std::string description;
	int damage; //I'm making damage intrinsic to all child classes, but it shouldn't really be used by non-equippable objects.
	bool equippable;

public:
	std::string describe() const;
	std::string type;
	int getDamage() const;
	std::string name;

};