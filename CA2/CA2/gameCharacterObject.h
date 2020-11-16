#ifndef gameCharacterObject_h
#define gameCharacterObject_h
#include <string>
#include <list>


class gameCharacterObject 
{

public:
	void spawnEnemy(std::string typeID, char enemyChar, int enemyHealth, int enemyAttack, int enemyX, int enemyY);
	void enemyInfo();
	bool enemyAlive();
	int getEnemyX();
	int getEnemyY();
	int setEnemyHealth(int value);
	int getEnemyHealth();
	int getEnemyAttack();
	int getBossHealth();
	int getBossAttack();
	void mapEnemy();

//protected:
	std::string e_typeID;
	int e_health;
	int e_attack;
	int e_x;
	int e2_x;
	int e3_x;
	int e_y;
	int e2_y;
	int e3_y;
	char e_Char;


};
#endif // !gameCharacterObject_h
#pragma once
