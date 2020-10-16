#include "Game.h"

void Game::init()
{
	// create the objects and assign each enemy and player unique typeID, 
	// health and x and y coords max health should be 170, speed is between 1 and 3. 
	// Place these GameCharacters in a list of GameCharacter 
	// pointers e.g. lpGameCharacters
}

void Game::render()
{
	// cycle through the list of GameCharacter ( enemy and player objects) 
	// and call the render function for each object
}

void Game::update()
{
	//cycle through the list of GameCharacter (enemy and player objects) and call the 
	// update function for each object
}

void Game::battle()
{
	// Check the list to see if two objects occupy the same coords declare that a battle must take  place.
	// The object with the higher health wins. The loser will have its health set to 0.
}

void Game::stats()
{
	// cycle through the list of GameCharacters ( enemy and player objects) 
	// and call the stats function for each object
}

void Game::clean()
{
	//remove any objects from the list whose health is 0 (Hint use isAlive function)
}
