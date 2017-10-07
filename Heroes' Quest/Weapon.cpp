#include "Weapon.h"



Weapon::Weapon()
{
}


//Weapon constructor	--	Class needs to be reworked into an abstract one.
Weapon::Weapon(std::string attackType)
{
	type = "Weapon";
	WeaponType = attackType;
	if (WeaponType == "melee")
	{
		Weapon::damage = 10;
		Weapon::description = "A wooden sword... it's not very fearsome.";
		Weapon::equippable = true;
		Weapon::name = "Wooden Sword";
	}
	else if (WeaponType == "ranged")
	{
		Weapon::damage = 7;
		Weapon::description = "Vaguely resembles a stick and some string.";
		Weapon::equippable = true;
		Weapon::name = "Wooden Bow";
	}
	else if (WeaponType == "mage")
	{
		Weapon::damage = 5;
		Weapon::description = "I'm pretty sure this is Bilbo's walking stick.";
		Weapon::equippable = true;
		Weapon::name = "Wooden Staff";
	}
	else
	{
		Weapon::damage = 7;
		Weapon::description = "Aren't these just sharpened popsicle sticks?";
		Weapon::equippable = true;
		Weapon::name = "Wooden Shortswords";
	}

}

//Weapon enchanting function
void Weapon::enchant()
{
	int manaNeeded = 100 * Weapon::enchantments.size();

	std::cout << "You need " << manaNeeded << " mana to enchant." << std::endl;
}