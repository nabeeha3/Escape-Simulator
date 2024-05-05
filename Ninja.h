#ifndef NINJA_H
#define NINJA_H

#include "Participant.h"
#include <string>

/*
Class: Hero
  Purpose: derived from the Participant class and represents one of the two heroes
Complex/Critical Members:
  Function: Hero()
    Purpose: constructor for Hero object
  Function: move(Pit* p)
    Purpose: computes a new position for the hero
  Function: incurDamage(Participant* p)
    Purpose: carries out the effects of a collision with the parameter participant
  Function: causeDamage()
    Purpose: returns 0 as heros do not cause damage
*/

class Ninja : public Participant
{
  public:
    Ninja(int=0, int=0);
    void incurDamage(Participant* p);
    int causeDamage();
    bool isSafe();

  private:
    int strength;
    bool poisoned;
};

#endif
