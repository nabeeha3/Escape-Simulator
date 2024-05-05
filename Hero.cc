#include "Hero.h"

#include <iostream>
using namespace std;


Hero::Hero(string n, char av, int row, int col)
    : name(n), health(MAX_HEALTH), rescued(false), Participant(av, row, col, new EscapeeBehaviour())
{
    
}

void Hero::incurDamage(Participant* p)
{
    int damage = p->causeDamage();

    if (damage == RESCUE)
    {
        rescued = true;
        // delete mvBehaviour; //????
        setMoveBehaviour(new RescuedBehaviour()); 

    }
    else //    if (health > 0) //????
    {
        health -= damage;
    }
    
    if (health <= 0)
    {
        dead = true;
        avatar = '+';
    }
}

int Hero::causeDamage()
{
    return 0;
}

bool Hero::isSafe()
{
    if (row == 0) //is 0 or MAX_ROW
    {
        return true;
    }

    return false;
}

string Hero::getName()
{
    return name;
}

int Hero::getHealth()
{
    return health;
}

bool Hero::getRescuedFlag()
{
    return rescued;
}