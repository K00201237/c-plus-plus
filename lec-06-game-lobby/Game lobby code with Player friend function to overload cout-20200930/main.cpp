//Game Lobby
//Simulates a game lobby where players wait
#include "Lobby.h"
ostream& operator<<(ostream& os, const Lobby& aLobby)
{
	Player* pIter = aLobby.m_pHead;

	os << "\nHere's who's in the game lobby:\n";
	if (pIter == 0)
	{
		os << "The lobby is empty.\n";
	}
	else
	{
		while (pIter != 0)
		{
			os << *(pIter) << endl;
			pIter = pIter->GetNext();
		}
	}

	return os;
}

int main()
{
	Lobby myLobby;
	int choice;

	do
	{
		cout << myLobby;
		cout << "\nGAME LOBBY\n";
		cout << "0 - Exit the program.\n";
		cout << "1 - Add a player to the lobby.\n";
		cout << "2 - Remove a player from the lobby.\n";
		cout << "3 - Clear the lobby.\n";
		cout << endl << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0: cout << "Good-bye.\n"; break;
		case 1: myLobby.AddPlayer(); break;
		case 2: myLobby.RemovePlayer(); break;
		case 3: myLobby.Clear(); break;
		default: cout << "That was not a valid choice.\n";
		}
	} while (choice != 0);

	return 0;
}
