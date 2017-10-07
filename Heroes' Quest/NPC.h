#pragma once

#include <vector>
#include "Object.h"


class NPC
{

protected:
	int baseHP;
	int STR;
	int DEX;
	int INT;
	int AGI;
	std::vector<Object> inventory; //    The inventory vector for npc's, so that looting/trading can be implemented. Add items via monsters' constructors

public:
	NPC();
	bool fightable;
	int currentHP;
	int getHP() { return currentHP; }
};