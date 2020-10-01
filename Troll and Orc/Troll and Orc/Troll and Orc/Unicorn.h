#ifndef UNICORN_H
#define UNICORN_H
#include ""

class Unicorn : public Creature
{
public:
	Unicorn(int health = 150, int speed = 10);
	virtual void Greet() const;
	void DisplayHealth() const;
};
#endif#
