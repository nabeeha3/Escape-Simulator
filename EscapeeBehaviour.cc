#include <iostream>
using namespace std;

#include "EscapeeBehaviour.h"

void EscapeeBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol)
{
    int rowMove = random(5) - 2;
    int colMove = random(3) - 1;

    newRow = oldRow + rowMove;
    newCol = oldCol + colMove;
}
