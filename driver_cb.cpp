#include "lab.h"

void driver_cb(void*)
{   
   fl_alert(driver->value()); //shows alert for the driver who is being added by the user
   std::string name;
   name = driver->value();
     d.Insert(name); //inserts the driver in the driversQ
    dbuff->text((d.getRQcontents().c_str())); // updates the FLTK driversQ box
    }
