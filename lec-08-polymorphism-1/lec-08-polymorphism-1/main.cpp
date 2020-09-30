#include "Boss.h"
#include "Enemy.h"
#include <vector>
#include <iostream>
using namespace std;


int main()
{
    cout << "Calling Attack() on Boss object through pointer to Enemy:\n";
    Enemy* pBadGuy = new Boss();
    pBadGuy->Attack();

    cout << "\n\nDeleting pointer to Enemy:\n";
    delete pBadGuy;
    pBadGuy = 0;

    cout << "Calling Attack() on emenmy iobject through pointrt to enemy.\n";
    Enemy* pEnemy = new Enemy;
    pEnemy->Attack();

    vector<Enemy*> vpEnemies;
    vpEnemies.push_back(pBadGuy);
    vpEnemies.push_back(pEnemy);

    vector<Enemy*>::const_iterator iter;
    cout << "Using a vector to cycle through all the enemies";

    for (iter = vpEnemies.begin(); iter != vpEnemies.end(); ++iter)
    {
        (*iter)->Attack();
    }

    cout << "Deleerting pointer to enemy";
    delete pBadGuy;
    pBadGuy = 0;

    return 0;
}