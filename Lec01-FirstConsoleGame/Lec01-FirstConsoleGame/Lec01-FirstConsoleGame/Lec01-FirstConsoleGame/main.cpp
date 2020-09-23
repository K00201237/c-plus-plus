#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	std::cout << "You are standing in an open field west of a white house, with a boarded front door. There is a small mailbox here";

	srand(static_cast<unsigned int>(time(0)));  

	int randomNumber = rand(); 

	int die = (randomNumber % 20) + 1; 
	cout << "You rolled a " << die << endl;

	std::getchar(); //keep the screen visible until a key is pressed


	return 0;
}