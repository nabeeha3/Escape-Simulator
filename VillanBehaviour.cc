#include <iostream>
using namespace std;

#include "VillanBehaviour.h"

void VillanBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol)
{
    int rowMove = random(2);
    int colMove = random(3) - 1;

    if (rowMove == 0)
    {
        newRow = oldRow - 1;
    }
    else
    {
        newRow = oldRow + 1;
        if (newRow > MAX_ROW - 7) //smth around max_row 7
        {
            newRow = oldRow;
        }
    }

    newCol = oldCol + colMove;
}
