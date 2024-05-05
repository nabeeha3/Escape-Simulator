#include <iostream>
using namespace std;
#include "Snorc.h"

Snorc::Snorc(int row, int col, int s)
    : strength(s), Participant('s', row, col, new VillanBehaviour()) 
{

}

void Snorc::incurDamage(Participant* p)
{

}

int Snorc::causeDamage()
{
    return strength;
}

bool Snorc::isSafe()
{
    return false;
}
