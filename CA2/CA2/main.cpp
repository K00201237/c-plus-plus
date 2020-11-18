#include "game.h"
#include <iostream>

// Creating game object
Game* m_game = 0;


int main() {

	// Game object calling menu function.
	m_game = new Game;
	m_game->menu();
	



}