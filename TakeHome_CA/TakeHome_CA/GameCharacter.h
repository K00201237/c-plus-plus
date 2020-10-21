#pragma once
#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H
#include <iostream>
#include <stdlib.h>
using namespace std;


class GameCharacter  //abstract class
{
protected:
	std::string m_typeID;
	int m_health;
	int m_speed;
	int x;
	int y;

public:
	
	void spawn(std::string typeID, int health, int speed, int x, int y);
	void render();
	virtual void update();
	void stats();
	bool isAlive();



};
#endif



