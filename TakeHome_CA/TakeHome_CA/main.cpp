#include "GameCharacter.h"
#include "Game.h"
#include <vector>
#include "Game.cpp"
#include "Player.cpp"



int main() {

	

	Game* pGame0 = new Game();
	pGame0->init();

	vector<Game*> vpGame;
	vpGame.push_back(pGame0);

	vector<Game*>::const_iterator iter;

	for (iter = vpGame.begin(); iter != vpGame.end(); ++iter)
	{
		(*iter)->render();
		(*iter)->update();
		(*iter)->battle();
		(*iter)->stats();
		(*iter)->clean();
	}

	
	return 0;
	
}