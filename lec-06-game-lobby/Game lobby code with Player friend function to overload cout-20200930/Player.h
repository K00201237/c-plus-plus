#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
//2019

using namespace std;

class Player
{
public:
	Player(const string& name = "");
	string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);
	friend ostream& operator<<(ostream& os, const Player& aPlayer);
private:
	string m_Name;
	Player* m_pNext;  //Pointer to next player in list
};



#endif PLAYER_H