#include "GameCharacter.h"
#include <iostream>



void Player::update()
{
	string input;
	&m_x;
	&m_y;
	cout << "User input required to determine where to move.\n";
	cout << "North, South, West, East.\n";
	cout << "Enter where you would like to move to.\n";
	cin >> input;
	while (m_health >= 0)
	{


		if (input == "North" || "north")
		{
			m_y--;
			cout << "X axis: " << m_x << " Y axis: " << m_y << endl;
			if (m_y == 0 && input == "North" || "north")
			{
				m_health - 10;
				cout << "You lost ten health point for hitting the wall.\n";
				cout << "Health: " << m_health;

			}
		}
		else if (input == "South" || "south")
		{
			m_y++;
			cout << "X axis: " << m_x << " Y axis: " << m_y << endl;
			if (m_y == 12 && input == "South" || "south")
			{
				m_health - 10;
				cout << "You lost ten health point for hitting the wall.\n";
				cout << "Health: " << m_health;
			}
		}
		else if (input == "West" || "west")
		{
			m_x--;
			cout << "X axis: " << m_x << " Y axis: " << m_y << endl;
			if (m_x == 0 && input == "West" || "west")
			{
				m_health - 10;
				cout << "You lost ten health point for hitting the wall.\n";
				cout << "Health: " << m_health;
			}
		}
		else if (input == "East" || "east")
		{
			m_x++;
			cout << "X axis: " << m_x << " Y axis: " << m_y << endl;
			if (m_x == 12 && input == "East" || "east")
			{
				m_health - 10;
				cout << "You lost ten health point for hitting the wall.\n";
				cout << "Health: " << m_health;
			}
		}
		else
		{
			cout << "Invalid option" << endl;
			return;
		}

		if (m_health < 1)
		{
			break;
		}
	}
}
