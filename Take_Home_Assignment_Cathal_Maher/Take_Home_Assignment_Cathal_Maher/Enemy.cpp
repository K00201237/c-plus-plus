#include "GameCharacter.h"
#include "Game.h"
#include <time.h>
#include <iostream>




void Enemy::update()
{
	srand((unsigned int)time(NULL));
	int choice = rand() % 10 + 1;
	const int arrayNum[4] = { m_x++, m_x--, m_y++, m_y-- };
	int RandIndex = rand() % 4;
	

	if (choice >= 8)
	{
		cout << "Enemy X Position: " << m_x << " Enemy Y Position: " << m_y << endl;
	}
	else
	{
		cout << "Enemy did not move\n" << endl;
	}

	
}


