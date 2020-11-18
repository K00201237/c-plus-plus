#include "gameCharacterObject.h"
#include <iostream>
#include "game.h"
#include <time.h>


// *Not Implemented*
// Function to spawn enemy
void gameCharacterObject::spawnEnemy(std::string typeID, char enemyChar, int enemyHealth, int enemyAttack, int enemyX, int enemyY)
{
	// Enemy Variables
	e_typeID = typeID;
	e_health = enemyHealth;
	e_attack = enemyAttack;
	e_x = enemyX;
	e_y = enemyY;
	e_Char = enemyChar;

	
}

// *Not Implemented* Display enemy info
void gameCharacterObject::enemyInfo()
{
	std::cout << "A " << e_typeID << " is about to attack!!" << std::endl;
	std::cout << "Enemy Health: " << e_health << std::endl;
	std::cout << "Enemy Attack: " << e_attack << std::endl;
	std::cout << "Enemy X coordinate: " << e_x << std::endl;
	std::cout << "Enemy Y coordinate: " << e_y << std::endl;
}

// *Not implemented* Check to see if enemy is alive
bool gameCharacterObject::enemyAlive()
{
	e_typeID = "enemy";
	if (e_health > 0)
	{
		return true;
	}
	else
	{
		std::cout << e_typeID << " has Died!" << std::endl;
		return false;
		
	}
}

// Assigning enemy a x coordinate
int gameCharacterObject::getEnemyX()
{
	srand(time(NULL));
	e_x = rand() % (33 - 7 + 1) + 7;
	e2_x = rand() % (18 - 3 + 1) + 3;
	e3_x = rand() % (18 - 3 + 1) + 3; 
	return e_x, e2_x, e3_x;
}

// Assigning enemy a y coordinate
int gameCharacterObject::getEnemyY()
{
	
	e_y = rand() % (14 - 7 + 1) + 7;
	e2_y = rand() % (16 - 19 + 1) + 7;
	e3_y = rand() % (8 - 23 + 1) + 7;
	return e_y, e2_y, e3_y;
}

// Assigning enemy health value
int gameCharacterObject::getEnemyHealth()
{
	e_health = rand() % (65 - 45 + 1) + 45;
	e_health2 = rand() % (70 - 50 + 1) + 50;;
	return e_health, e_health2;
	
}

// Assigning enemy attack value
int gameCharacterObject::getEnemyAttack()
{
	
	e_attack = rand() % (40 - 30 + 1) + 30;
	e_attack2 = rand() % (45 - 35 + 1) + 35;
	return e_attack, e_attack2;

}

// Assigning Boss health value
int gameCharacterObject::getBossHealth()
{
	e_health = rand() % 125 + 100;
	return e_health;

}

// Assigning Boss Attack value
int gameCharacterObject::getBossAttack()
{
	
	e_attack = rand() % 55 + 30;
	return e_attack;

}




