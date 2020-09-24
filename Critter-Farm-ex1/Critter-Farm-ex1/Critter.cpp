#include "Critter.h"

Critter::Critter(const string& name) :
    m_Name(name)
{}

string Critter::GetName() const
{
    return m_Name;
}
