#include "Minotaur.h"



Minotaur::Minotaur()    //  Setting by default what a minotaur has upon creation
{

	baseHP = 50;
	currentHP = baseHP;
	fightable = true;

	STR = 10;
	DEX = 5;
	INT = 7;
	AGI = 15;

}


Minotaur::~Minotaur()
{
}
