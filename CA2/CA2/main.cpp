#include "game.h"
#include <iostream>

Game* m_game = 0;
gameCharacterObject* m_gameO = 0;

int main() {

	m_game = new Game;
	m_gameO = new gameCharacterObject;

	//m_gameO->enemyInfo();
	m_game->menu();
	



}