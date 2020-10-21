#include <string>
#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#pragma once
using namespace std;

class GameCharacter {



public:
	void spawn(std::string typeID, int health, int speed, int x, int y);
	void render();
	virtual void update() const;
	void stats();
	bool isAlive();

protected:

	std::string m_typeID = " ";
	int m_health;
	int m_speed;
	int m_x;
	int m_y;


};


class Enemy : public GameCharacter
{
public:

	void update();
};

class Player : public GameCharacter
{
public:
	void update();
};


#endif