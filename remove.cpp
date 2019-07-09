#include "lab.h"

bool RBQUEUE::Remove (std::string &s)
{
    if(isEmpty())
    {
        return false;
        }
   s = buf[front]; //sets s to the value being removed
    front = nextIndex(front); // moves front to the next index
    return true;
    }
