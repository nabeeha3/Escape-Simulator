#include <iostream>
using namespace std;

#include "RescuedBehaviour.h"

void RescuedBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol)
{
    newRow = oldRow + 1;
    newCol = oldCol;
}
