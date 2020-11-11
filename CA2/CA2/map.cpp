#include"map.h"
using namespace std;

// Draw map on console
void Map::printMap() {
    {
        for (int i = 0; i < 10; i++) {
            cout << Map::map[i] << endl;
        }

    }
}


// Contains functions to start game
void Map::setupGame() {
    Map::spawnPlayer(1, 5, Map::p1, 'P');
    Map::printMap();
    Map::input();
    
}

// Gives player coords, sets character and stores position
void Map::spawnPlayer(int x, int y, player& p, char playChar)
{
    p.pChar = playChar;
    Map::map[x][y] = p.pChar;
    p.health = 10;
    p.position.x = x;
    p.position.y = y;

    m_x = p.position.x;
    m_y = p.position.y;
    m_health = p.health;
    
    
}

// Displaying coords and accepting user input
void Map::input()
{
    cout << "Player X coordinate: " << m_x << endl;
    cout << "Player Y coordinate: " << m_y << endl;
    cout << "Player Health: " << m_health << endl;
    cout << "Enter a direction: " << endl;
    char input;
    cin >> input;
    
       if (input == 's' && m_x > 0 && m_x < 10) {
           m_x++;
           Map::spawnPlayer(m_x, m_y, Map::p1, 'P');
           Map::printMap();
           Map::input();
           
       }
       else 
       {
           cout << "Reached end of level." << endl;
       }
        
    

}