#ifndef ESCAPE_H
#define ESCAPE_H

#include "Snorc.h"
#include "Hero.h"
#include "List.h"
#include "Ninja.h"

/*
Class: Escape
  Purpose: serves as the control object for the simulation
Complex/Critical Members:
  Function: Escape()
    Purpose: constructor for Escape object
  Function: ~Escape()
    Purpose: destructor for Escape object
  Function: runEscape()
    Purpose: implements the game loop
  Function: spawnSnorc()
    Purpose: dynamically allocates a new snorc
  Function: isOver()
    Purpose: find a participant that is occupying the same position as parameter participant
  Function: moveParticipants()
    Purpose: moves each participant in participant array
*/

class Escape
{
  public:
    Escape();
    ~Escape();
    void runEscape();
    bool withinBounds(int row, int col);

  private:
    int numSnorcs;
    List<Participant*> participants;
    Hero* hero1;
    Hero* hero2;
    Hero* timmy;
    Hero* harold;

    void spawnSnorc();
    void spawnNinja();
    void moveParticipants();
    Participant* checkForCollision(Participant* p);
    bool isOver();
    void printOutcome(Hero* h);
    void printPit();
    void printStatus(Hero* h); //helper

};

#endif
