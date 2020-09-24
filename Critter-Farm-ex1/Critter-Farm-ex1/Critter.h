#ifndef CRITTER_H
#define CRITTER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Critter
{
public:
    Critter(const string& name = "");
    string GetName() const;

private:
    string m_Name;
};


#endif