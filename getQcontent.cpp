#include "lab.h"

std::string LLQUEUE::getQcontent()
{
    std::string str;
    NODE *node;
        for(node = front; node; node = node->next)// sets node to the front, if node is not null, make node equal the the next node
        {
            str += node->info.info + "\n"; //stors the data in the list into str string one by one
            
            }
    return str; //returns the whole str with all the data
    }
