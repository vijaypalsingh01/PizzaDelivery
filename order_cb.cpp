#include "lab.h"

ORDER ord; //one
LLQUEUE o;
LLQUEUE c;
RBQUEUE d;
RBQUEUE currD;
void order_cb(void*, void*)
{  
    fl_alert(pizza->value()); //shows alert with input values
    fl_alert(address->value());
   
    ord.info = pizza->value(); 
    ord.addr = address->value();
   
    o.Insert(ord);//inserts the data into order Q
    
    buff->text((o.getQcontent().c_str())); // updates th order Q in FLTK

    Fl::add_timeout(10,cook_cb); //calls back the cook function 
    }
