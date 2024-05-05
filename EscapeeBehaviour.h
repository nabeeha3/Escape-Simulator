#ifndef ESCAPEE_BEHAVIOUR_H
#define ESCAPEE_BEHAVIOUR_H

#include "MoveBehaviour.h"

/*
Class: EscapeeBehaviour
  Purpose: serves as the control object for the simulation
Complex/Critical Members:
  Function: Escape()
    Purpose: constructor for Escape object
  Function: moveParticipants()
    Purpose: moves each participant in participant array
*/

class EscapeeBehaviour : public MoveBehaviour
{
  public:
    void move(int , int , int& , int&);

};

#endif
