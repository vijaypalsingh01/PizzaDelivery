#include "lab.h"
LLQUEUE::~LLQUEUE()
{
    NODE *next;
    while (front)
    {
        next= front->next;
        delete front; //deletes the front 
        front = next; //sets the front to the next node
        }
    }
