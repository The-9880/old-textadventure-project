#include "Player.h"


//constructor for the player class - I don't know what kind of stuff we'll preset here.
//Maybe take some config info from the user beforehand? Meh.
Player::Player(std::string chosen, std::string chosenName)
{
	name = chosenName;

	if (chosen == "Warrior")
	{

		STR = 10;
		INT = 5;
		DEX = 7;
		AGI = 6;
		baseHP = 50;
	}
	if (chosen == "Mage")
	{

		STR = 5;
		INT = 10;
		DEX = 6;
		AGI = 6;
		baseHP = 40;
	}
	if (chosen == "Rogue")
	{

		STR = 7;
		INT = 6;
		DEX = 6;
		AGI = 8;
		baseHP = 45;
	}
	if (chosen == "Ranger")
	{

		STR = 6;
		INT = 6;
		DEX = 7;
		AGI = 10;
		baseHP = 45;
	}


	currentHP = baseHP;
	strDamage = STR * 1.2;

}

//the ATTACK function
//This will be part of the battle-sequence, and will only handle the player attacking the target
void Player::attack(NPC* target)//remove the "std::cout"s later, they'll be part of the battleSequence function.
{

	if (target->fightable == true) //quick check to see if it's attackable in the first place.
	{

		//check if the player has a weapon equipped, else use STR to roll for damage.
		for (std::vector<Object>::const_iterator iter = equipped.begin(); iter != equipped.end(); ++iter)
		{
			if ((*iter).type == "Weapon")
			{
				//So now we have a viable target and a weapon, let's do this.
				target->currentHP -= iter->getDamage();//This'd count as 'pure' damage; implement a defence-points system later.
				std::cout << target->currentHP << std::endl;
				break;
			}
			else
			{

				//No weapon found, continue through the loop until we reach the end
				if (iter == equipped.end())
				{
					//We're at the end of the loop and found no weapon, time to use str
					target->currentHP -= strDamage;
					std::cout << target->currentHP << std::endl;
				}

				break;
			}

		}

	}
	else
	{
		std::cout << "You cannot attack that target!" << std::endl;
	}

}


//overloading the equip function to take object names instead
void Player::equip(std::string objectName)
{
	int found = 0;

	for (std::vector<Object>::iterator iter = inventory.begin(); iter != inventory.end(); ++iter)
	{

		if (iter->name == objectName)
		{
			found = 1;
			equipped.push_back(*iter);
			std::cout << "You have equipped " << objectName << ".\n\n";
			inventory.erase(iter);
			break;//the break also serves the purpose of avoiding complications if more than two of the same object are in the inventory
		}

	}
	if (found == 0)
	{
		std::cout << "That item does not exist.\n" << std::endl;
	}

}

void Player::equip(Object toEquip)
{

	int found = 0;
	for (std::vector<Object>::iterator iter = inventory.begin(); iter != inventory.end(); ++iter)
	{

		if (iter->name == toEquip.name)
		{
			found = 1;
			equipped.push_back(toEquip);
			std::cout << "You have equipped " << toEquip.name << ".\n\n";
			inventory.erase(iter);
			break;
		}

	}
	if (found == 0)
	{
		std::cout << "That item does not exist.\n" << std::endl;
	}


}

//player unequip function
void Player::unequip(Object toUnequip)
{

	int found = 0;
	for (std::vector<Object>::iterator iter = equipped.begin(); iter != equipped.end(); ++iter)
	{
		if (iter->name == toUnequip.name)
		{
			found = 1;
			equipped.push_back(toUnequip);
			equipped.erase(iter);
			break;
		}
	}

}


//player see inventory function
void Player::seeInventory()
{

	int i = 0;
	std::cout << "\nYour Inventory: " << std::endl;

	if (inventory.size() == 0)
	{
		std::cout << "\nYou have no items in inventory." << std::endl;
	}

	else

	{
		for (std::vector<Object>::const_iterator iter = inventory.begin(); iter != inventory.end(); ++iter)
		{

			std::cout << 1 + i << ". " << iter->name << std::endl;

		}
	}

}
