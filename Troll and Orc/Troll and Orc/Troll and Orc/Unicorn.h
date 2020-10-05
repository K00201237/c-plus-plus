#ifndef UNICORN_H
#define UNICORN_H
#include "Creature.h"

class Unicorn : public Creature
{
public:
	Unicorn(int health = 150, int speed = 10);
	virtual void Greet() const;
	void DisplayHealth() const;
};
#endif#
