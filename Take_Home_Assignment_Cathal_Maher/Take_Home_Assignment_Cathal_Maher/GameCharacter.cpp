#include "GameCharacter.h"
#include <iostream>
#include <time.h>


void GameCharacter::spawn(std::string typeID, int health, int speed, int x, int y)
{
	// create an object

	GameCharacter* obj1 = new GameCharacter();
	obj1->m_typeID = typeID;
	obj1->m_health = health;
	obj1->m_speed = speed;
	obj1->m_x = x;
	obj1->m_y = y;

}

void GameCharacter::render()
{
	srand((unsigned int)time(NULL));
	m_typeID = "Enemy";
	m_health = m_x = rand() % 30 + 80;
	m_speed = m_x = rand() % 3 + 1;
	m_x = rand() % 12 + 1;
	m_y = rand() % 12 + 1;
	cout << "Type: " << m_typeID << endl;
	cout << "Health: " << m_health << endl;
	cout << "Speed: " << m_speed << endl;
	cout << "X coordinate: " << m_x << endl;
	cout << "Y coordinate: " << m_y << endl;
	cout << endl;

	m_typeID = "Player";
	m_health = m_x = rand() % 30 + 140;
	m_speed = m_x = rand() % 3 + 1;
	m_x = rand() % 12 + 1;
	m_y = rand() % 12 + 1;
	cout << "Type: " << m_typeID << endl;
	cout << "Health: " << m_health << endl;
	cout << "Speed: " << m_speed << endl;
	cout << "X coordinate: " << m_x << endl;
	cout << "Y coordinate: " << m_y << endl;
	cout << endl;




}

void GameCharacter::update() const
{
}


void GameCharacter::stats()
{
	cout << "Type: " << m_typeID << endl;
	cout << "Health: " << m_health << endl;
	cout << "Speed: " << m_speed << endl;
	cout << "X coordinate: " << m_x << endl;
	cout << "Y coordinate: " << m_y << endl;
	cout << endl;
}

bool GameCharacter::isAlive()
{
	//return true if its  health is greater than 0
	//return false;

	if (m_health > 0)
	{
		return true;
		cout << "Alive " << endl;
	}
	else
	{
		return false;
		cout << "Dead " << endl;
	}
}
