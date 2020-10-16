#include "GameCharacter.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"
#include <vector>



int main()
{
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



}