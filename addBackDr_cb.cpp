#include "lab.h"

void addBackDr_cb(void*)
{
    std::string Dback; //will be used to display alert
    currD.Remove(Dback);//removes the driver from the queue of drivers who are currently delivering
    d.Insert(Dback); //inserts the driver to the original driver queue who is ready to deliver
    dbuff->text((d.getRQcontents().c_str())); //updates the text in FLTK
    std::string alrt; //string that will help display alert
    alrt = Dback + " is back from delivery";
    fl_alert(alrt.c_str()); //shows alert when the driver is back
    }
