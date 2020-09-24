#ifndef FARM_H
#define FARM_H
#include "Critter.h"

class Farm
{
public:
    Farm(int spaces = 1);
    void Add(const Critter& aCritter);
    void RollCall() const;

private:
    vector<Critter> m_Critters;
};

#endif
