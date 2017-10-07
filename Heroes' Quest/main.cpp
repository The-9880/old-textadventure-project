#include <iostream>
#include <vector>
#include <ctime>
#include "Object.h"
#include "Weapon.h"
#include "NPC.h"
#include "Minotaur.h"
#include "Player.h"

using namespace std;



//global variables declared here-----------------------------------------------------
vector<Player> players; //This vector will hold all of the players.
bool multiplayer = false;


//global functions declared here-----------------------------------------------------
void battleSequence(Player* player, NPC* target); //NEEDS REWORKING TO INTEGRATE MULTIPLAYER SYSTEM
void addToStat(Player* player, string stat, int amount);
void initialize();//handles the setup for the game




int main()
{

	initialize();
	if (players.size() > 1)
	{
		multiplayer = true;
	}

	//the game begins-----------------------
	//this is the loop that takes all the players' actions. Needs to be called BETWEEN story events to take decisions
	//Later, I'll modify it to allow the players to set off on different paths.
	for (int turn = 0; turn < players.size(); ++turn)
	{
		Player* player = &players[turn];//the pointer to the active player.

		if (multiplayer == true)
		{
			cout << "It is now " << player->name << "'s turn.\n\n";
		}

		vector<Object>::const_iterator iter; //handy iterator for inventory or equipped items.

		//	---------------	Testing block for functions -------------------
		cout << "You are given a weapon." << endl;

		//testing inventory/equipped functions
		//Need to update by creating the pointer forms of the equip function, then give a player a first weapon based on their class
		Weapon firstSword("melee");
		player->inventory.push_back(firstSword);
		player->seeInventory();
		player->equip(firstSword);
		player->seeInventory();

		for (iter = player->equipped.begin(); iter != player->equipped.end(); ++iter)
		{
			cout << (*iter).describe() << endl;//beware, this loop describes all the items and not just the weapon we added.
		}
		//	----------------------- Ending Testing block


		//	---------------------	Start the actual game loop here

	}
	return 0;
}



//Extended Function Definitions here---------------------------------------------------
void addToStat(Player* player, string stat, int amount)
{
	if (stat == "STR")
		player->STR += amount;
	player->strDamage = player->STR * 1.2;
	if (stat == "INT")
		player->INT += amount;
	if (stat == "DEX")
		player->DEX += amount;
	if (stat == "AGI")
		player->AGI += amount;
}

void battleSequence(Player* player, NPC* target)
{

	// The battle sequence should start out with the players setting up their formation.
	// Use a vector to handle a party of monsters
	// Warriors can only attack the forwardmost enemies, archers and mages can attack all
	// Rogues can use throwing knives to fight if they are not at the front.
	// (Will need a variable to determine if someone has any moves or not. If not, skip them in the sequence.)
	// Can probably iterate through the players vector and the monster-party vector to print out a CLI-style graphic, representing everyone's positions
	// The interface will show how much HP each person has left beside their name.
	// From there, Warriors can only attack if the monster is forward.
	// [Need to figure out a system for indicating who is forward. Don't need to bother with who is backwards.]


	string choice;//probably overload the variable to take either string or int

	//give options: attack, ability, run, items
	cout << "You may: " << endl;
	cout << "1. Attack" << endl;
	cout << "2. Use an ability " << endl;
	cout << "3. Use your items " << endl;
	cout << "4. Run Away" << endl;
	cout << endl;
	cin >> choice;

	player->attack(target);
	//Plan out the fighting layout.

}

void initialize()
{
	string temp_Name;
	string temp_Class;
	int numberOfPlayers;

	//initialization stage------------------
	cout << "Welcome to Quest!" << endl;
	cout << "Enter the number of players: " << endl;
	cin >> numberOfPlayers;

	for (int i = 0; i < numberOfPlayers; ++i)
	{
		cout << "\nYou will need to create your hero." << endl;
		cout << "Player " << 1 + i << ", What is your hero name? (Maximum of 10 characters):  " << endl;
		cin >> temp_Name;
		cout << "\nWelcome, " << temp_Name << ". Would you like to be a Warrior, Mage, Ranger or Rogue?" << endl;
		//add a proper check here for validity and the class
		cin >> temp_Class;
		players.push_back(Player(temp_Class, temp_Name));
		cout << endl;
		cout << endl;
	}

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

}