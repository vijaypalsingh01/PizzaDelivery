#include "lab.h"
void cook_cb(void*)
{   
    o.Remove(ord); //removes the data from the order queue
    buff->text((o.getQcontent().c_str()));//updates the data for FLTK in the order Q
    c.Insert(ord); //inserts the data into the cooked Q
    
    cbuff->text((c.getQcontent().c_str())); //Updates the FLTK text box for cooked Q
    
    std::string alrt = ord.info + " is cooked";
    fl_alert(alrt.c_str()); //shows alert that the pizza is cooked
    
    Fl::add_timeout(3,delivery_cb); //calls back the delivery_cb function with 3 sec delay for us to actually see whats happening
    
}
