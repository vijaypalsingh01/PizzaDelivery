#include "lab.h"
bool LLQUEUE::Insert (ORDER &info)
{
    NODE *newnode = new NODE; //allocates a new node
    if(!newnode) return false;
    newnode->info = info;
    newnode->next = 0;
    
    if(rear == 0)//if rear is null
    {
        front = rear= newnode; //set front and rear to the new node
        }
    else
    {
        rear->next = newnode;
        rear= newnode;
        }

return true;
}
