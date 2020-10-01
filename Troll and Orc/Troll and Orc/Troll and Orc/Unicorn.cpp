#include "Unicorn.h"
Unicorn::Unicorn(int health, int speed) :
	Creature(health, speed)
{}

void Unicorn::Greet() const
{
	cout << "The Unicorn roars hello.\n";
}
void Unicorn::DisplayHealth() const
{
	cout << "The Unicorn's health is " << m_Health << "\n";
}