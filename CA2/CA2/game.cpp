#include "game.h"
#include "enemy.h"
#include "gameCharacterObject.h"
#include <time.h>
using namespace std;

// Draw map on console
void Game::printMap() {
    {
        for (int i = 0; i < 24; i++) {
            cout << Game::map[i] << endl;
        }
        
    }
}


void Game::init()
{
    e_enemy1 = new Enemy();
    e_enemy2 = new Enemy();
    e_enemy3 = new Enemy();
    
    e_enemy1->spawnEnemy("Zombie", 'Z', 50, 10, 10, 10);
    e_enemy2->spawnEnemy("Goblin", 'G', 60, 10, 3, 12);
    e_enemy3->spawnEnemy("Giant Spider", 'S', 40, 10, 25, 10);

    e_gameCharacterObjectList.push_back(e_enemy1);
    e_gameCharacterObjectList.push_back(e_enemy2);
    e_gameCharacterObjectList.push_back(e_enemy3);
    
}

void Game::battle()
{
    int input;

    cout << "You have encountered an enemy! Prepare to fight!" << endl;
    cout << endl;
    cout << "1: Attack" << endl;
    cout << endl;
    if (Game::map[m_x][m_y] == Game::map[e2_x][e2_y])
    {
        cin >> input;
        do
        {
            if (input == 1)
            {
                m_eneHealth = m_eneHealth - m_attack;
                cout << "You strike the enemy and deal " << m_attack << " damage." << endl;
                cout << "Enemy health: " << m_eneHealth << endl;
                if (m_eneHealth > 0)
                {
                    m_health = m_health - m_eneAttack;
                    cout << "The enemy strikes back and deals " << m_eneAttack << " damage." << endl;
                    cout << "Player health: " << m_health << endl;
                }
                if (m_eneHealth < 0)
                {
                    cout << "You have defeated the enemy!." << endl;

                    Game::map[e2_x][e2_y] = temp;
                    e2_x = 1;
                    e2_y = 0;
                    temp = Game::map[e2_x][e2_y];
                    Game::map[e2_x][e2_y] = ' ';
                }
            }

        } while (m_eneHealth > 0);
    }

    if (Game::map[m_x][m_y] == Game::map[e3_x][e3_y])
    {
        cin >> input;
        do
        {
            if (input == 1)
            {
                m_eneHealth = m_eneHealth - m_attack;
                cout << "You strike the enemy and deal " << m_attack << " damage." << endl;
                cout << "Enemy health: " << m_eneHealth << endl;
                if (m_eneHealth > 0)
                {
                    m_health = m_health - m_eneAttack;
                    cout << "The enemy strikes back and deals " << m_eneAttack << " damage." << endl;
                    cout << "Player health: " << m_health << endl;
                }
                if (m_eneHealth < 0)
                {
                    cout << "You have defeated the enemy!." << endl;

                    Game::map[e3_x][e3_y] = temp;
                    e3_x = 1;
                    e3_y = 1;
                    temp = Game::map[e3_x][e3_y];
                    Game::map[e3_x][e3_y] = ' ';
                }
            }

        } while (m_eneHealth > 0);
    }

    if (Game::map[m_x][m_y] == Game::map[b_x][b_y])
    {
        cin >> input;
        do
        {
            if (input == 1)
            {
                m_bossHealth = m_bossHealth - m_attack;
                cout << "You strike the Boss and deal " << m_attack << " damage." << endl;
                cout << "Boss enemy health: " << m_bossHealth << endl;
                if (m_bossHealth > 0)
                {
                 
                    cout << "The Boss enemy strikes back and deals " << m_bossAttack << " damage." << endl;
                    m_health = m_health - m_bossAttack;
                    cout << "Player health: " << m_health << endl;
                }
                if (m_bossHealth < 0)
                {
                    cout << "You have defeated the Boss!." << endl;
                    Game::gameComplete();
                   
                }
                if (m_health < 0)
                {
                    cout << "You have died!." << endl;
                    cout << "You will return to the menu." << endl;
                    Game::menu();

                }
            }

        } while (m_bossHealth > 0);
    }
    
    



    //int enemyX;
    //int enemyY;
    //int enemyHealth;	//player variables

    //std::list <gameCharacterObject*>::iterator iter;
    //player is at the start of the list
    //enemyX = e_gameCharacterObjectList.front()->getEnemyX();	//get the players coords
    //enemyY = e_gameCharacterObjectList.front()->getEnemyY();
    //enemyHealth = e_gameCharacterObjectList.front()->getEnemyHealth(); //get the players health

    //
    //srand(time(NULL));
    //enemyX = rand() % (20 - 1 + 1) + 1;
    //enemyY = rand() % (50 - 1 + 1) + 1;

    //Game::map[enemyX][enemyY] = temp;
    //temp = Game::map[enemyX][enemyY];
    //Game::map[enemyX][enemyY] = 'E';

    //cycle through the list, if its an enemy check to see if it occupies the same position as the player
    //for (iter = e_gameCharacterObjectList.begin(); iter != e_gameCharacterObjectList.end(); ++iter)
    //{
    //    if ((*iter)->getType() == "enemy" && (playerX == (*iter)->getX()) && (playerY == (*iter)->getY()))	//if an enemy is on the same position as the player
    //    {
    //        if (m_health >= (*iter)->getEnemyHealth())	//if the player has more health
    //        {
    //            std::cout << "Enemy Destroyed" << std::endl;
    //            (*iter)->setEnemyHealth(0);	//set the enemies health to zero

    //        }
    //        else
    //        {
    //            std::cout << "YOU DIED" << std::endl;
    //            e_gameCharacterObjectList.front()->setEnemyHealth(0);	//set the players health to zero

    //        }
    //    }
    //}
}



void Game::info()
{
    std::list<gameCharacterObject*>::const_iterator it;

    for (it = e_gameCharacterObjectList.begin(); it != e_gameCharacterObjectList.end(); it++) {
        (*it)->enemyInfo();
    }
   // std::cout << (*it) << endl;

}

// Contains functions to start game
void Game::setupGame() {
    Game::spawnTreasure(t_x, t_y);
    Game::spawnEnemy(e_x, e_y, e_health, e_attack, e_Char);
    //Game::battle();
    Game::spawnPlayer(4, 45, Game::p1, 'P');
    Game::printMap();
    Game::input();
    
    
}



// Gives player coords, sets character and stores position
void Game::spawnPlayer(int x, int y, player& p, char playChar)
{
    p.pChar = playChar;
    Game::map[x][y] = p.pChar;
    p.health = 100;
    p.attack = rand() % 50 + 45;
    p.position.x = x;
    p.position.y = y;

    m_x = p.position.x;
    m_y = p.position.y;

    p_Char = p.pChar;
    m_health = p.health;
    m_attack = p.attack;
    potions = 2;
    

}

void Game::spawnTreasure(int x, int y)
{
    x = t_x;
    y = t_y;
    srand(time(NULL));
    t_x = rand() % (20 - 1 + 1) + 1;
    t_y = rand() % (50 - 1 + 1) + 1;
    
    Game::map[t_x][t_y] = temp;
    temp = Game::map[t_x][t_y];
    Game::map[t_x][t_y] = 'T';

}

void Game::spawnEnemy(int x, int y, int enemyHealth, int enemyAttack, char enemyChar)
{
    x = gameCharacterObject::getEnemyX();
    y = gameCharacterObject::getEnemyY();

    e_x = gameCharacterObject::getEnemyX();
    e_y = gameCharacterObject::getEnemyY();

    e2_x = gameCharacterObject::getEnemyX();
    e2_y = gameCharacterObject::getEnemyY();

    e3_x = gameCharacterObject::getEnemyX();
    e3_y = gameCharacterObject::getEnemyY();

    enemyHealth = gameCharacterObject::getEnemyHealth();
    enemyAttack = gameCharacterObject::getEnemyAttack();
   
    m_eneHealth = enemyHealth;
    m_eneAttack = enemyAttack;

    Game::map[e_x][e_y] = temp2;
    temp2 = Game::map[e_x][e_y];
    Game::map[e_x][e_y] = 'E';

    Game::map[e2_x][e2_y] = temp;
    temp = Game::map[e2_x][e2_y];
    Game::map[e2_x][e2_y] = 'E';

    Game::map[e3_x][e3_y] = temp;
    temp = Game::map[e3_x][e3_y];
    Game::map[e3_x][e3_y] = 'E';

    

}



// Displaying coords and accepting user input
void Game::input()
{
    

    if (Game::map[m_x][m_y] == Game::map[e_x][e_y] || Game::map[m_x][m_y] == Game::map[e2_x][e2_y] || Game::map[m_x][m_y] == Game::map[e3_x][e3_y])
    {
        Game::battle();
    }

    if (Game::map[m_x][m_y] == Game::map[t_x][t_y])
    {
        potions = potions + 1;
        cout << "You found a Health potion!" << endl;

        Game::map[t_x][t_y] = temp;
        t_x = 0;
        t_y = 0;
        temp = Game::map[t_x][t_y];
        Game::map[t_x][t_y] = ' ';
    }

    if (e2_x == 1 && e2_y == 0 && e3_x == 1 && e3_y == 1)
    {
        b_x = 16;
        b_y = 16;
        m_bossHealth = gameCharacterObject::getBossHealth();
        m_bossAttack = gameCharacterObject::getBossAttack();
        Game::map[b_x][b_y] = temp;
        temp = Game::map[b_x][b_y];
        Game::map[b_x][b_y] = 'B';

    }

    if (Game::map[m_x][m_y] == Game::map[b_x][b_y])
    {
        Game::battle();
    }
   
    cout << "Player X coordinate: " << m_y << endl;
    cout << "Player Y coordinate: " << m_x << endl;
    cout << "Player Health: " << m_health << endl;
    cout << "Health potions: " << potions << endl;
    cout << "Press 'Q' to use a Health potion" << endl <<endl;
    cout << "Enter a direction: " << endl;
    int previous;
    char input;
    cin >> input;
    cout << " " << endl;

    if (input == 'q') {
        
        if (potions == 1 || potions > 1)
        {
            cout << "You have used a health potion!" << endl;
            potions--;
            m_health = m_health + 20;
            Game::input();
        }
        if (potions == 0)
        {
            cout << "You are out of health potions!" << endl;
            Game::input();
        }

    }

    if (input == 's' && m_x > 0 && m_x < 22) {
        Game::moveDown();

    }
    if (input == 's' && m_x == 22)
    {
        cout << "You are unable to go this way." << endl;
        Game::input();
    }

    if (input == 'w' && m_x < 23 && m_x > 3)
    {
        Game::moveUp();
    }
    if (input == 'w' && m_x == 3)
    {
        cout << "You are unable to go this way." << endl;
        Game::input();
    }

    if (input == 'd' && m_y > 0 && m_y < 50)
    {
        Game::moveRight();
    }
    if (input == 'd' && m_y == 50)
    {
        cout << "You are unable to go this way." << endl;
        Game::input();
    }

    if (input == 'a' && m_y < 51 && m_y > 1)
    {
        Game::moveLeft();
    }
    if (input == 'a' && m_y == 1)
    {
        cout << "You are unable to go this way." << endl;
        Game::input();
    }

    else
    {
        cout << "Reached end of level." << endl;
    }

}

void Game::moveRight()
{ 
    Game::map[m_x][m_y] = temp;
    m_y++;
    temp = Game::map[m_x][m_y];
    Game::map[m_x][m_y] = 'P';
    system("cls");
    printMap();
    input();

}

void Game::moveLeft()
{
    Game::map[m_x][m_y] = temp;
    m_y--;
    temp = Game::map[m_x][m_y];
    Game::map[m_x][m_y] = 'P';
    system("cls");
    printMap();
    input();
}

void Game::moveUp()
{
    Game::map[m_x][m_y] = temp;
    m_x--;
    temp = Game::map[m_x][m_y];
    Game::map[m_x][m_y] = 'P';
    system("cls");
    printMap();
    input();
}

void Game::moveDown()
{
    Game::map[m_x][m_y] = temp;
    m_x++;
    temp = Game::map[m_x][m_y];
    Game::map[m_x][m_y] = 'P';
    system("cls");
    printMap();
    input();
}

void Game::menu()
{
    cout << "________          _____                  .___" << endl;
    cout << "\______ \   _____/ ____\____   ____    __| _/" << endl;
    cout << " |    |  \_/ __ \   __\/ __ \ /    \  / __ | " << endl;
    cout << " |    `   \  ___/|  | \  ___/|   |  \/ /_/ | " << endl;
    cout << "/_______  /\___  >__|  \___  >___|  /\____ | " << endl;
    cout << "        \/     \/          \/     \/      \/ " << endl;
    cout << "_____.___.                                   " << endl;
    cout << "\__  |   | ____  __ _________                " << endl;
    cout << " /   |   |/  _ \|  |  \_  __ \               " << endl;
    cout << " \____   (  <_> )  |  /|  | \/               " << endl;
    cout << " / ______|\____/|____/ |__|                  " << endl;
    cout << " \/                                          " << endl;
    cout << "  ___ ___                                    " << endl;
    cout << " /   |   \  ____   _____   ____              " << endl;
    cout << "/    ~    \/  _ \ /     \_/ __ \             " << endl;
    cout << "\    Y    (  <_> )  Y Y  \  ___/             " << endl;
    cout << " \___|_  / \____/|__|_|  /\___  >            " << endl;
    cout << "       \/              \/     \/             " << endl;
    cout << "     " << endl;
    cout << "You are exhausted and sleep deprived, your town has     " << endl;
    cout << "been under siege for days now. The town walls won't     " << endl;
    cout << "last long. You are the only person left who is able    " << endl;
    cout << "to fight. You need to defend your home and drive the     " << endl;
    cout << "enemy back!     " << endl;
    cout << "     " << endl;
    cout << "Press '1' to begin.     " << endl;

    int input;
    cin >> input;
    if (input == 1)
    {
        Game::setupGame();
    }
}

void Game::gameComplete()
{
    cout << "You have Beaten the game!." << endl;
    Game::menu();
}


