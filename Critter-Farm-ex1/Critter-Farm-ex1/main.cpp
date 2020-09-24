#include "Farm.h"

int main()
{
    Critter crit("Poochie");
    Critter crit2("Ringo");
    cout << "My critter's name is " << crit.GetName() << endl;

    cout << "\nCreating critter farm.\n";
    Farm myFarm(3);

    cout << "\nAdding three critters to the farm.\n";
    myFarm.Add(Critter("Moe"));
    myFarm.Add(Critter("Larry"));
    myFarm.Add(Critter("Curly"));
    myFarm.Add(crit2);

    cout << "\nCalling Roll...\n";
    myFarm.RollCall();

    return 0;
}