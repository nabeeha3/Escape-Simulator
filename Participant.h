#ifndef  PARTICIPANT_H
#define PARTICIPANT_H

#include "MoveBehaviour.h"
#include "EscapeeBehaviour.h"
#include "RescuedBehaviour.h"
#include "RescuerBehaviour.h"
#include "VillanBehaviour.h"


#include "defs.h"
/*
Class: Participant
  Purpose: base class for every kind of participant in the simulation
Complex/Critical Members:
  Function: Participant()
    Purpose: constructor for Participant elements
  Function: ~Participant()
    Purpose: destructor for position of Participant object
  Function: move(Pit* p)
    Purpose: pure virtual; compute successive new positions for a participant
  Function: incurDamage(Participant* p)
    Purpose: pure virtual; determine how this participant reacts to the damage caused by another participant during a collision
  Function: causeDamage()
    Purpose: pure virtual; determine how much damage this participant causes in a collision with another participant
  Function: collide(Participant* p)
    Purpose: determine whether or not the participant is currently located at the same position as the parameter participant
*/

class Participant
{
  public:
    Participant(char = 'p', int=0, int=0, MoveBehaviour* mb= nullptr);
    virtual ~Participant();
    virtual void incurDamage(Participant* p) = 0; 
    virtual int causeDamage() = 0; 
    virtual bool isSafe() = 0;
    void move(); 
    char getAvatar();
    int getRow();
    int getCol();
    bool isDead();
    bool validPos(int, int);
    void setMoveBehaviour(MoveBehaviour*);

  protected:
    char avatar;
    bool dead;
    int row;
    int col;
    MoveBehaviour* mvBehaviour;

};

#endif
