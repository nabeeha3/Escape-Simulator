#include <iostream>
using namespace std;

#include "RescuerBehaviour.h"

void RescuerBehaviour::move(int oldRow, int oldCol, int& newRow, int& newCol)
{
    newRow = oldRow - 1;
    newCol = oldCol;
}
