#ifndef SNORC_H
#define SNORC_H

#include "Participant.h"

/*
Class: Snorc
  Purpose: derived from the Participant class and represents a snorc
Complex/Critical Members:
  Function: Snorc()
    Purpose: constructor for Snorc object
  Function: move(Pit* p)
    Purpose: computes a new position for the snorc
  Function: incurDamage(Participant* p)
    Purpose: does nothing as snorcs do not incur damage
  Function: causeDamage()
    Purpose: returns the snorc’s strength, as this represents the amount of damage that they can cause to other participants
*/

class Snorc : public Participant
{
  public:
    Snorc(int=0, int=0, int=0);
    // void move(Pit* p);
    void incurDamage(Participant* p);
    int causeDamage();
    bool isSafe();

  private:
    int strength;
};

#endif
