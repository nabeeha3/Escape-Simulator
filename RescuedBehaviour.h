#ifndef RESCUED_BEHAVIOUR_H
#define RESCUED_BEHAVIOUR_H
#include "MoveBehaviour.h"

/*
Class: RescuedBehaviour
  Purpose: serves as the control object for the simulation
Complex/Critical Members:
  Function: Escape()
    Purpose: constructor for Escape object
  Function: moveParticipants()
    Purpose: moves each participant in participant array
*/

class RescuedBehaviour : public MoveBehaviour
{
  public:
    void move(int oldRow, int oldCol, int& newRow, int& newCol);
};

#endif
