#include "Ninja.h"

#include <iostream>
using namespace std;


Ninja::Ninja(int row, int col)
    :strength(0), Participant('N', row, col, new RescuerBehaviour()) //set avatar??
{

}

void Ninja::incurDamage(Participant* p)
{
    if (poisoned == true)
    {
        return;
    }
    else
    {
        int damage = p->causeDamage();
        
        if (damage == RESCUE)
        {
            return;
        }
        else if (damage == 0)
        {
            // delete mvBehaviour; //????
            setMoveBehaviour(new RescuedBehaviour()); 
        }
        else
        {
            poisoned = true;
            avatar = 'S';
            //change behaviour to villan
            // delete mvBehaviour; //????
            setMoveBehaviour(new VillanBehaviour()); 
            strength = random(3) + 6;
        }


    }

}

int Ninja::causeDamage()
{
    if (poisoned == true)
    {
        return strength;
    }
    else
    {
        return RESCUE;
    }
}

bool Ninja::isSafe()
{
    if (poisoned == true)
    {
        return false;
    }

    if (row == 0 || row == MAX_ROW) //is 0 or MAX_ROW
    {
        return true;
    }
    else false;
}

