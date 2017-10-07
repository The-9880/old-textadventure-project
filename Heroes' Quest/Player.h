#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Object.h"
#include "NPC.h"

class Player
{

public:
	Player(std::string chosen, std::string chosenName);

	std::vector<Object> equipped;
	std::vector<Object> inventory;

	void attack(NPC* target);
	void equip(std::string objectName);// Next, I need to update this so that it'll automatically unequip an item if that slot is equipped.
	void equip(Object toEquip);
	void unequip(Object toUnequip);// may need to overload this function as well.
	void status();// define; this function will give the player the status of their hero (hp, equipped, location, etc.)
	void seeInventory();
	friend void addToStat(Player* player, std::string stat, int amount);// could make this a function of the Player class rather than a friend function

	int currentHP;
	std::string name;
	std::string heroType;
	int strDamage;// Recalculated every time addToStat runs. I'll need to modify this later for bonuses from equipped items

protected:
	int baseHP;
	int STR;
	int INT;
	int DEX;
	int AGI;

};