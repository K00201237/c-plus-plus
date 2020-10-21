#include "GameCharacter.h"
#include <string>
using namespace std;



void GameCharacter::spawn(std::string typeID, int health, int speed, int x, int y)
{



	
	
}

void GameCharacter::render()
{
	
}

void GameCharacter::update()
{
	//cout << update;
}

void GameCharacter::stats()
{
	cout << "Name: " << m_typeID;
	cout << "Health: " << m_health;
	cout << "Speed: " << m_speed;
	cout << "X: " << x;
	cout << "Y: " << y;
}

bool GameCharacter::isAlive()
{
	return false;
}
