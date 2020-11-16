#include "gameCharacterObject.h"
#include <iostream>
#include "game.h"
#include <time.h>



void gameCharacterObject::spawnEnemy(std::string typeID, char enemyChar, int enemyHealth, int enemyAttack, int enemyX, int enemyY)
{
	e_typeID = typeID;
	e_health = enemyHealth;
	e_attack = enemyAttack;
	e_x = enemyX;
	e_y = enemyY;
	e_Char = enemyChar;

	
}

void gameCharacterObject::enemyInfo()
{
	std::cout << "A " << e_typeID << " is about to attack!!" << std::endl;
	std::cout << "Enemy Health: " << e_health << std::endl;
	std::cout << "Enemy Attack: " << e_attack << std::endl;
	std::cout << "Enemy X coordinate: " << e_x << std::endl;
	std::cout << "Enemy Y coordinate: " << e_y << std::endl;
}

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

int gameCharacterObject::getEnemyX()
{
	//srand(time(NULL));
	e_x = 4;//rand() % 10 + 7;
	e2_x = 9;//rand() % 14 + 12;
	e3_x = 15; //rand() % 10 + 7;
	return e_x;
}

int gameCharacterObject::getEnemyY()
{
	//srand(time(NULL));
	e_y = rand() % 14 + 7;
	e2_y = rand() % 25 + 7;
	e3_y = rand() % 35 + 7;
	return e_y;
}

int gameCharacterObject::setEnemyHealth(int value)
{
	
	e_health = 60;
	
	return e_health;
}

int gameCharacterObject::getEnemyHealth()
{
	e_health  = rand() % 60 + 50;
	return e_health;
	
}

int gameCharacterObject::getEnemyAttack()
{
	//srand(time(NULL));
	e_attack = rand() % 40 + 25;
	return e_attack;

}

int gameCharacterObject::getBossHealth()
{
	e_health = rand() % 125 + 100;
	return e_health;

}

int gameCharacterObject::getBossAttack()
{
	
	e_attack = rand() % 55 + 10;
	return e_attack;

}

void gameCharacterObject::mapEnemy()
{

}


