#include "game.h"
#include "enemy.h"
#include "gameCharacterObject.h"
#include <time.h>
using namespace std;

// For loop to draw the 24 lines creating the map
void Game::printMap() {
    {
        for (int i = 0; i < 24; i++) {
            cout << Game::map[i] << endl;
        }
        
    }
}


// *Not Implemeted* I tried to create enemy objects and assign them spawnEnemy function values and putting them in a list
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

// Battle function
void Game::battle()
{
    int input;

    cout << "You have encountered an enemy! Prepare to fight!" << endl;
    cout << endl;
    cout << "1: Attack" << endl;
    cout << endl;

    // If player and enemy coordinates align ask the user to attack
    if (Game::map[m_x][m_y] == Game::map[e2_x][e2_y])
    {
        cin >> input;
        do
        {
            if (input == 1)
            {
                // Reduce enenmy health by player attack value and print it out
                e_health = e_health - m_attack;
                cout << "You strike the enemy and deal " << e_health << " damage." << endl;
                cout << "The enemy releases an agonizing roar " << endl;
                cout << "Enemy health: " << e_health << endl;
                // If enemy health value is greater than 0. Enemy attacks player, reduce player health by enmy attack value and print it out
                if (e_health > 0)
                {
                    m_health = m_health - e_attack;
                    cout << "The enemy strikes back and deals " << e_attack << " damage." << endl;
                    cout << "Player health: " << m_health << endl;
                }
                // If enemy health is less than 1, player defeats enemy, and enemy coordinates are moved outside of the playable area and char is blank
                if (e_health < 1)
                {
                    cout << "You have defeated the enemy!." << endl;

                    Game::map[e2_x][e2_y] = temp;
                    e2_x = 1;
                    e2_y = 0;
                    temp = Game::map[e2_x][e2_y];
                    Game::map[e2_x][e2_y] = ' ';
                }
                // If player health is less than 1, print out statement and call menu function
                if (m_health < 1)
                {
                    cout << "You have died!." << endl;
                    cout << "You will return to the menu." << endl;
                    Game::menu();

                }
            }

            // continue looping while enemy health is greater than 0
        } while (e_health > 0);
    }

    // Second enemy
    if (Game::map[m_x][m_y] == Game::map[e3_x][e3_y])
    {
        cin >> input;
        do
        {
            if (input == 1)
            {
                e_health2 = e_health2 - m_attack;
                cout << "You strike the enemy and deal " << m_attack << " damage." << endl;
                cout << "The enemy releases an agonizing roar " << endl;
                cout << "Enemy health: " << e_health2 << endl;
                if (e_health2 > 0)
                {
                    m_health = m_health - e_attack2;
                    cout << "The enemy strikes back and deals " << e_attack2 << " damage." << endl;
                    cout << "Player health: " << m_health << endl;
                }
                if (e_health2 < 1)
                {
                    cout << "You have defeated the enemy!." << endl;

                    Game::map[e3_x][e3_y] = temp;
                    e3_x = 1;
                    e3_y = 1;
                    temp = Game::map[e3_x][e3_y];
                    Game::map[e3_x][e3_y] = ' ';
                }
                if (m_health < 1)
                {
                    cout << "You have died!." << endl;
                    cout << "You will return to the menu." << endl;
                    Game::menu();

                }
            }

        } while (e_health2 > 0);
    }

    // Boss enemy
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
                if (m_bossHealth < 1)
                {
                    cout << "You have defeated the Boss!." << endl;
                    cout << "You have saved your home!." << endl;
                    Game::gameComplete();
                   
                }
                if (m_health < 1)
                {
                    cout << "You have died!." << endl;
                    cout << "You will return to the menu." << endl;
                    Game::menu();

                }
            }

        } while (m_bossHealth > 0);
    }
    
    

    // *Not Implemeted*  I was trying to assign enemies I put in the list x and y coordinates and compare with the players coordinates

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
    //    if ((*iter)->getType() == "enemy" && (m_x == (*iter)->getX()) && (m_y == (*iter)->getY()))	//if an enemy is on the same position as the player
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


// *Not Implemeted* I was trying to print out info of enemies in the list
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
    Game::spawnBomb(bombX, bombY);
    Game::spawnEnemy(e_x, e_y, e_health, e_attack, e_Char);
    Game::spawnPlayer(4, 45, Game::p1, 'P');
    Game::printMap();
    Game::input();
    
    
}



// Gives player coords, sets character and stores position, assigns player health and attack values, assign potions value
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
    m_attack = rand() % 50 + 45;
    potions = 2;
    

}

// Assign x and y coordinates for treasure randomly, assign map coords , assign char
void Game::spawnTreasure(int x, int y)
{
    x = t_x;
    y = t_y;
    srand(time(NULL));
    t_x = rand() % (20 - 1 + 1) + 1;
    t_y = rand() % (50 - 1 + 1) + 1;

    t2_x = rand() % (20 - 1 + 1) + 1;
    t2_y = rand() % (50 - 1 + 1) + 1;
    
   
    Game::map[t_x][t_y] = 'T';

   
    Game::map[t2_x][t2_y] = 'T';

}

void Game::spawnBomb(int x, int y)
{
    x = bombX;
    y = bombY;
    
    bombX = rand() % (20 - 1 + 1) + 1;
    bombY = rand() % (20 - 1 + 1) + 1;

    bomb2X = rand() % (20 - 1 + 1) + 1;
    bomb2Y = rand() % (50 - 1 + 1) + 1;

    
    Game::map[bombX][bombY] = '*';

    Game::map[bomb2X][bomb2Y] = '*';
}

// spawn enemy function, assigns enemies x and y coordinates, health and attack. also places the enemy character on map
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
   
    e_health = gameCharacterObject::getEnemyHealth();
    e_attack = gameCharacterObject::getEnemyAttack();

    e_health2 = gameCharacterObject::getEnemyHealth();
    e_attack2 = gameCharacterObject::getEnemyHealth();

    // This enemy does not appear after adding the two following enemies. Not sure why this happens.

    Game::map[e_x][e_y] = 'E';

  
    Game::map[e2_x][e2_y] = 'E';

  
    Game::map[e3_x][e3_y] = 'E';

    

}



// Displaying coords and accepting user input
void Game::input()
{
    
    // If player coordinates match an enemys coordinates call the battle function
    if (Game::map[m_x][m_y] == Game::map[e_x][e_y] || Game::map[m_x][m_y] == Game::map[e2_x][e2_y] || Game::map[m_x][m_y] == Game::map[e3_x][e3_y])
    {
        Game::battle();
    }

    // If player coordinates match the treasure coordinates, increase potions in inventory
    if (Game::map[m_x][m_y] == Game::map[t_x][t_y])
    {
        potions = potions + 1;
        cout << "You found a Health potion!" << endl;

        // Move traseure to coordinates 0,5 and print blank Character
        Game::map[t_x][t_y] = temp;
        t_x = 0;
        t_y = 5;
        temp = Game::map[t_x][t_y];
        Game::map[t_x][t_y] = ' ';
    }

    // If player coordinates match the treasure coordinates, increase player attack value
    if (Game::map[m_x][m_y] == Game::map[t2_x][t2_y])
    {
        m_attack = m_attack + 10;
        cout << "You found a Magic sword! Your attack has been permantly increased" << endl;

        
        Game::map[t2_x][t2_y] = temp;
        t2_x = 0;
        t2_y = 0;
        temp = Game::map[t2_x][t2_y];
        Game::map[t2_x][t2_y] = ' ';
    }

    // If player coordinates match the bomb coordinates, decrease player health value
    if (Game::map[m_x][m_y] == Game::map[bombX][bombY])
    {
        m_health = m_health - 25;
        cout << "You Hit a BOMB!!!" << endl;
        cout << "Player Health: " << m_health << endl;

        
        Game::map[bombX][bombY] = temp;
        bombX = 0;
        bombY = 6;
        temp = Game::map[bombX][bombY];
        Game::map[bombX][bombY] = ' ';
        
    }

    // If player coordinates match the bomb coordinates, decrease player health value
    if (Game::map[m_x][m_y] == Game::map[bomb2X][bomb2Y])
    {
        m_health = m_health - 25;
        cout << "You Hit a BOMB!!!" << endl;
        cout << "Player Health: " << m_health << endl;


        Game::map[bomb2X][bomb2Y] = temp;
        bomb2X = 0;
        bomb2Y = 7;
        temp = Game::map[bomb2X][bomb2Y];
        Game::map[bomb2X][bomb2Y] = ' ';

    }

    // If enemy locations equal these values, spawn boss on coordinates 16,16 and inherit health and attack values.
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

    // If player coordinates equal boss coordinates call battle function
    if (Game::map[m_x][m_y] == Game::map[b_x][b_y])
    {
        Game::battle();
    }
   
    // Print players stats and ask them to enter a direction
    cout << "Player X coordinate: " << m_y << endl;
    cout << "Player Y coordinate: " << m_x << endl;
    cout << "Player Health: " << m_health << endl;
    cout << "Health potions: " << potions << endl;
    cout << "Press 'Q' to use a Health potion" << endl <<endl;
    cout << "Enter a direction: 'W' = North  'S' = South  'D' = East  'A' = West " << endl;
    int counter = 0;
    char input;
    cin >> input;
    cout << " " << endl;

    do
    {
        counter++;
    
    // If player has equal or greter than 1 potion, decrement potions, increase player health and call input function
    if (input == 'q' || input == 'Q') {
        
        if (potions == 1 || potions > 1)
        {
            cout << "You have used a health potion!" << endl;
            potions--;
            m_health = m_health + 20;
            Game::input();
        }
        // If player has 0 potions print statement and call input function
        if (potions == 0)
        {
            cout << "You are out of health potions!" << endl;
            Game::input();
        }

    }

    // If player enters w,s,a,d call relevant function unless they are at a map boundary, print statement.
    if (input == 's' && m_x > 0 && m_x < 22 || input == 'S' && m_x > 0 && m_x < 22) {
        Game::moveDown();

    }
    if (input == 's' && m_x == 22 || input == 'S' && m_x == 22)
    {
        cout << "You are unable to go this way." << endl;
        Game::input();
    }

    if (input == 'w' && m_x < 23 && m_x > 3 || input == 'W' && m_x < 23 && m_x > 3)
    {
        Game::moveUp();
    }
    if (input == 'w' && m_x == 3 || input == 'W' && m_x == 3)
    {
        cout << "You are unable to go this way." << endl;
        Game::input();
    }

    if (input == 'd' && m_y > 0 && m_y < 50 || input == 'D' && m_y > 0 && m_y < 50)
    {
        Game::moveRight();
    }
    if (input == 'd' && m_y == 50 || input == 'D' && m_y == 50)
    {
        cout << "You are unable to go this way." << endl;
        Game::input();
    }

    if (input == 'a' && m_y < 51 && m_y > 1 || input == 'A' && m_y < 51 && m_y > 1)
    {
        Game::moveLeft();
    }
    if (input == 'a' && m_y == 1 || input == 'A' && m_y == 1)
    {
        cout << "You are unable to go this way." << endl;
        Game::input();
    }

    else
    {
        cout << "Invalid option." << endl;
        Game::input();
    }
    } while (input < 10);
    cout << "Night Time" << endl;
}

// Move the player right function. Assign current map coords to a temp variable, increment specified coordinate, assign temp to new coordiantes,
// assign Character, clear the screen, call the print map function and input function 
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

// Move the player left function. Assign current map coords to a temp variable, decrement specified coordinate, assign temp to new coordiantes,
// assign Character, clear the screen, call the print map function and input function
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

// Move the player up function. Assign current map coords to a temp variable, decrement specified coordinate, assign temp to new coordiantes,
// assign Character, clear the screen, call the print map function and input function

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

// Move the player down function. Assign current map coords to a temp variable, increment specified coordinate, assign temp to new coordiantes,
// assign Character, clear the screen, call the print map function and input function

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
    //Title Screen and backstory

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
    cout << "Select Difficulty:     " << endl;
    cout << "Press '1' to play on easy." << endl;
    cout << "Press '2' to play on normal. " << endl;
    cout << "Press '3' to play on hard.  " << endl;

    // Selecting level difficulty and adjusting enemy health and attack values.
    int input;
    cin >> input;
    if (input == 1)
    {
        e_health = e_health * 0.5;
        e_health2 = e_health2 * 0.5;
        e_attack = e_attack * 0.5;
        e_attack2 = e_attack2 * 0.5;
        m_bossHealth = m_bossHealth * 0.5;
        m_bossAttack = m_bossAttack * 0.5;
        Game::setupGame();
    }
    if (input == 2)
    {
        Game::setupGame();
    }
    if (input == 3)
    {
        e_health = e_health * 1.25;
        e_health2 = e_health2 * 1.25;
        e_attack = e_attack * 1.25;
        e_attack2 = e_attack2 * 1.25;
        m_bossHealth = m_bossHealth * 1.25;
        m_bossAttack = m_bossAttack * 1.25;
        Game::setupGame();
    }
    else
    {
        cout << "invalid option." << endl;
        Game::menu();
    }
}

// Game complete function, print statement and call menu function
void Game::gameComplete()
{
    cout << "You have Beaten the game!." << endl;
    Game::menu();
}






