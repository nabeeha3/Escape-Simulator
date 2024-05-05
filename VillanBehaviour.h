#ifndef VILLAN_BEHAVIOUR_H
#define VILLAN_BEHAVIOUR_H
#include "MoveBehaviour.h"

/*
Class: VillanBehaviour
  Purpose: serves as the control object for the simulation
Complex/Critical Members:
  Function: Escape()
    Purpose: constructor for Escape object
  Function: moveParticipants()
    Purpose: moves each participant in participant array
*/

class VillanBehaviour : public MoveBehaviour
{ 
  public:
    void move(int oldRow, int oldCol, int& newRow, int& newCol);
};

#endif
