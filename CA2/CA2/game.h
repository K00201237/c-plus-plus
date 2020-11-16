#ifndef game_h
#define game_h

#include <iostream>
#include <string>
#include "gameCharacterObject.h"

//Player Coords
class coords {
public:
	int x;
	int y;
	
};

// Player postion, ascii character and health
class player {
public:
	coords position;
	char pChar;
	int health;
	int attack;
};


class Game : public gameCharacterObject
{
	
private:
	gameCharacterObject* e_enemy1;
	gameCharacterObject* e_enemy2;
	gameCharacterObject* e_enemy3;

	std::list<gameCharacterObject*> e_gameCharacterObjectList;

public:
	player p1;
	char map[24][53] = {
		"                                                    ",
		"     P = Player    T = Treasure    E = Enemy        ",
		"####################################################",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"#                                                  #",
		"####################################################",
	};

	void init();
	void battle();
	void info();
	void setupGame();
	void spawnPlayer(int x, int y, player& p, char playChar);
	void spawnTreasure(int x, int y);
	void spawnEnemy(int x, int y, int enemyHealth, int enemyAttack, char enemyChar);
	void printMap();
	void input();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void menu();
	void gameComplete();



protected:
	int m_x;
	int m_y;
	int t_x;
	int t_y;
	int prevX;
	int prevY;
	int m_health;
	int m_attack;
	int potions;
	int m_eneHealth;
	int m_eneAttack;
	int m_bossHealth;
	int m_bossAttack;
	int b_x;
	int b_y;
	char p_Char;
	char temp;
	char temp2;
};

#endif