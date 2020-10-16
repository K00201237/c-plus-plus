#include <string>
#ifndef GAMECHARACTER
#define GAMECHARACTER
#pragma once
using namespace std;

class GameCharacter {

protected:
	std::string m_typeID;
	int m_health;
	int m_speed; 
	int m_x;
	int m_y;

public:
	void spawn(std::string typeID, int health, int speed, int x, int y);
	void render();
	virtual void update();
	void stats();
	bool isAlive();

};

class Enemy
{
};

class Player
{
};


#endif