#include "Participant.h"

using namespace std;

Participant::Participant(char av, int r, int c, MoveBehaviour* mb)
    : avatar(av), dead(false), row(r), col(c), mvBehaviour(mb)
{

}

Participant::~Participant()
{
    delete mvBehaviour; //????
}


bool Participant::isDead()
{
    return dead;
}

char Participant::getAvatar()
{
    return avatar;
}

int Participant::getRow()
{
    return row;
}

int Participant::getCol()
{
    return col;
}

void Participant::move()
{
    if (!isDead() && validPos(row, col))
    {
        int newRow = row;
        int newCol = col;

        mvBehaviour->move(row, col, newRow, newCol);

        if (validPos(newRow, newCol))
        {
            row = newRow;
            col = newCol;
        }

    }
}

void Participant::setMoveBehaviour(MoveBehaviour* mb)
{
    mvBehaviour = mb;
}

//helper 
bool Participant::validPos(int r, int c)
{
    if (row > 0 && row < MAX_ROW - 1 && col > 0 && col < MAX_COL - 1)
    {
        return true;
    } 
    else
    {
        return false;
    }
}
