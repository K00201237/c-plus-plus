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

// Player postion, ascii character, health and attack
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
	// *Not implemented* Was trying to create enemy object and put them in a list
	gameCharacterObject* e_enemy1;
	gameCharacterObject* e_enemy2;
	gameCharacterObject* e_enemy3;

	std::list<gameCharacterObject*> e_gameCharacterObjectList;

public:
	// Player object and creating char map
	player p1;
	char map[24][53] = {
		"                                          B = Boss  ",
		"P = Player    T = Treasure    E = Enemy   * = Bomb  ",
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

	// Functions
	void init();
	void battle();
	void info();
	void setupGame();
	void spawnPlayer(int x, int y, player& p, char playChar);
	void spawnTreasure(int x, int y);
	void spawnBomb(int x, int y);
	void spawnEnemy(int x, int y, int enemyHealth, int enemyAttack, char enemyChar);
	void printMap();
	void input();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void menu();
	void gameComplete();


	// Variables
protected:
	int m_x;
	int m_y;
	int t_x;
	int t_y;
	int t2_x;
	int t2_y;
	int bombX;
	int bombY;
	int bomb2X;
	int bomb2Y;
	int prevX;
	int prevY;
	int m_health;
	int m_attack;
	int potions;
	int m_bossHealth;
	int m_bossAttack;
	int b_x;
	int b_y;
	char p_Char;
	char temp;
	char temp2;
};

#endif