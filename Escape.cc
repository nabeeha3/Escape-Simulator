#include <iostream>
using namespace std;

#include "Escape.h"

Escape::Escape()
    : numSnorcs(0), hero1(nullptr), hero2(nullptr)
{
    srand( (unsigned)time( NULL ) );

    int hero1Col = random(10) + 7;
    int hero2Col = random(10) + 7; 

    while (hero2Col == hero1Col)
    {
        hero2Col = random(10) + 7; 
    }

    timmy = new Hero("Timmy", 'T', MAX_ROW - 2, hero1Col);
    harold = new Hero("Harold", 'H', MAX_ROW - 2, hero2Col);

    hero1 = timmy;
    hero2 = harold;

    participants += timmy;
    participants += harold;

}

void Escape::runEscape() 
{
    while (!isOver()) 
    {
        system("clear");
        
        spawnSnorc();
        moveParticipants();
        
        usleep(200000);

        printPit();
    }
}

bool Escape::isOver()
{
    return ((timmy->isDead() || timmy->isSafe()) && (harold->isDead() || harold->isSafe()));
}

bool Escape::withinBounds(int row, int col)
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

void Escape::spawnSnorc() 
{
    if (numSnorcs < MAX_SNORCS) 
    {
        int spawnPr = random(100);
        if (spawnPr < SNORC_SPAWN)
        {
            int snorcRow = random(6) + 15; //recheck
            int snorcCol = random(MAX_COL - 1) + 1;
            int strength = random(3) + 2;

            Snorc* newSnorc = new Snorc(snorcRow, snorcCol, strength);

            participants += newSnorc;
            numSnorcs++;
        }
    }
}

void Escape::spawnNinja() 
{
    if (numSnorcs < MAX_SNORCS) 
    {
        int spawnPr = random(100);
        if (spawnPr < NINJA_SPAWN)
        {
            int ninjaRow = 0; //recheck
            int ninjaCol = random(MAX_COL - 1) + 1;

            Ninja* newNinja = new Ninja(ninjaRow, ninjaCol);

            participants += newNinja;
        }
    }
}

Participant* Escape::checkForCollision(Participant* p)
{
    Participant* partArray[MAX_ARR];
    int size;

    participants.convertToArray(partArray, size);

    for (int i = 0; i < size; i++)
    {
        if ( partArray[i]->getRow() == p->getRow() && partArray[i]->getCol() == p->getCol() )
        {
            return partArray[i];
        }
    }
    return nullptr;
}
 
void Escape::moveParticipants()
{
    Participant* partArray[MAX_ARR];
    int size;

    participants.convertToArray(partArray, size);

    for (int i = 0; i < size; i++)
    {
        partArray[i]->move();

        Participant* collidedParticipant = checkForCollision(partArray[i]);

        if (collidedParticipant != nullptr) 
        {
            if (!collidedParticipant->isSafe() && !collidedParticipant->isDead())
            {
                collidedParticipant->incurDamage(partArray[i]);
                partArray[i]->incurDamage(collidedParticipant);
            }
        }

    }
}

void Escape::printPit()
{
    const char templateGrid[MAX_ROW+2][MAX_COL+3]={ 
        "---------------------------",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "|                         |",
        "---------------------------"
    };

    char snorcPit[MAX_ROW+2][MAX_COL+3];

    for (int i = 1; i < MAX_ROW; i++) 
    {
        for (int j = 1; j < MAX_COL; j++) 
        {
            snorcPit[i][j] = templateGrid[i][j];
        }
    }

    Participant* partArray[MAX_ARR];
    int size;

    participants.convertToArray(partArray, size);

    for (int i = 0; i < size; i++)
    {
        int rowPos = partArray[i]->getRow();
        int colPos = partArray[i]->getCol();

        snorcPit[rowPos][colPos] = partArray[i]->getAvatar();
    }

    for (int i = 0; i < MAX_ROW+2; i++) 
    {
        for (int j = 0; j < MAX_COL+3; j++) 
        {
            if (i == MAX_ROW - 2 && j == MAX_COL) 
            {
                cout << snorcPit[i][j] << "   " << hero1->getName() << ": " << hero1->getHealth();
                printStatus(hero1);
            }
            else if (i == MAX_ROW - 1 && j == MAX_COL)
            {
               cout << snorcPit[i][j] <<  "   " << hero2->getName() << ": " << hero2->getHealth();
                printStatus(hero2);
            }
            else
            {
                cout << snorcPit[i][j];
            }
        }
        cout << endl;
    }



}

void Escape::printOutcome(Hero* h)
{
    if(h->isDead()) {
        cout << h->getName() << " died..."  << endl;
    }
    else if(h->isSafe()) {
        cout << h->getName() << " escaped on his own!" << endl;
    }
    else if(h->getRescuedFlag()) {
        cout << h->getName() << " was safely rescued!" << endl;
    }
}

void Escape::printStatus(Hero* h)
{
    if(h->isDead()) {
        cout << "   Deceased"  << endl;
    }
    else if(h->isSafe()) {
        cout << "   Escaped" << endl;
    }
    else if(h->getRescuedFlag()) {
        cout << "   Rescued" << endl;
    }
}

