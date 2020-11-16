#ifndef enemy_h
#define enemy_h

#include <iostream>
#include "gameCharacterObject.h"


class Enemy : public gameCharacterObject
{
public:
	void update();

};

#endif