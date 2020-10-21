#include <string>
#ifndef GAME_H
#define GAME_H
#include "GameCharacter.h"
#pragma once
class Game
{

public:
	void init();
	void render();
	void update();
	void battle();
	void stats();
	void clean();
};


#endif
