#include "Critter.h"
void testDestructor();
void testCopyConstructor(Critter aCopy);
void testAssignmentOp();

int main()
{
	testDestructor();
	cout << endl;

	Critter crit("Poochie", 5);
	crit.Greet();

	testCopyConstructor(crit);
	crit.Greet();
	cout << endl;

	testAssignmentOp();

	return 0;
}

void testDestructor()
{
	cout << "about to call Test Deconstructor \n";
	Critter toDestroy("Rover", 3);
	toDestroy.Greet();
}

void testCopyConstructor(Critter aCopy)
{
	cout << "about to call test copy constructor \n";
	aCopy.Greet();
}

void testAssignmentOp()
{
	Critter crit1("crit1", 7);
	Critter crit2("crit2", 9);
	//overloaded assignment called 
	crit1 = crit2;
	crit1.Greet();
	crit2.Greet();
	cout << endl;

	Critter crit3("crit", 11);
	crit3 = crit3;
	crit3.Greet();
}

