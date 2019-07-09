#include "lab.h"  
      
std::string RBQUEUE::getRQcontents()
{
    int curr;
    std::string drivers;
    for(int curr=front; curr<rear; curr=nextIndex(curr))//sets current to the front, if curr is less than rear, move current to the next index after front
    {
        drivers += buf[curr] + "\n"; //stores all the data into the string
        
        }
    return drivers; //returns the string with all the data
    }
