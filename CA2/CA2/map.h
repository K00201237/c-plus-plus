#ifndef map_h
#define map_h

#include <iostream>
#include <string>

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
};


class Map
{
public:
	player p1;
	char map[10][20] = {
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
		"                   ",
	};
	void setupGame();
	void spawnPlayer(int x, int y, player& p, char playChar);
	void printMap();
	void input();

protected:
	int m_x;
	int m_y;
	int m_health;
};

#endif
