#include "GameCharacter.h"
#include "Game.h"
#include <vector>


int main()
{
	

	Game* start = new Game();
	start->init();
	Enemy* gcEne = new Enemy();
	gcEne->update();
	Player* gcPla = new Player();
	gcPla->update();
	

	Game* pGame0 = new Game();
	pGame0->init();

	vector<Game*> vpGame; 
	vpGame.push_back(pGame0);

	vector<Game*>::const_iterator iter;

	
	for (int i = 0; i < 20; i++)
	{
		for (iter = vpGame.begin(); iter != vpGame.end(); ++iter)
		{
			(*iter)->render();
			(*iter)->update();
			(*iter)->battle();
			(*iter)->stats();
			(*iter)->clean();
		}
	}


}