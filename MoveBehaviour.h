#ifndef MOVE_BEHAVIOUR_H
#define MOVE_BEHAVIOUR_H

#include "random.cc"
#include "defs.h"

/*
Class: MoveBehaviour
  Purpose: serves as the control object for the simulation
Complex/Critical Members:
  Function: Escape()
    Purpose: constructor for Escape object
  Function: moveParticipants()
    Purpose: moves each participant in participant array
*/

class MoveBehaviour
{
  public:
    virtual void move(int oldRow, int oldCol, int& newRow, int& newCol) = 0;
};

#endif
