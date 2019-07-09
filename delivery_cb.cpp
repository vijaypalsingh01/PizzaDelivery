#include "lab.h"

void delivery_cb(void*)
{   
    
     if(d.isEmpty()) //checks if the drivers Q is empty
    {
       fl_alert("Not enough drivers"); //shows alerts that there are no more drivers
       Fl::add_timeout(5,delivery_cb); //checks again if there are any drivers in the Q after 5 sec
        }
    else
    {
        std::string dname;
        d.Remove(dname);//removes the driver who is ready for delivery
        currD.Insert(dname); //puts the same driver in a different RBQ which is for the drivers who are out for delivery
        c.Remove(ord);//removes the pizza from the cooked Q
        std::string temp = dname + " is delivering the "+ ord.info + " to " + ord.addr;
        fl_alert(temp.c_str());//alert that shows who is delivering the pizaa and where
        cbuff->text((c.getQcontent().c_str())); // updates FLTK text in cooked Q box
        dbuff->text((d.getRQcontents().c_str())); // updates FLTK text in drivers Q box
        Fl::add_timeout(100,addBackDr_cb); //cb to the function which adds the drivers back after they do delivery
        }
   
    }
