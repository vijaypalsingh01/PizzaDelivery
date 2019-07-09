#include "lab.h"
/*
g++ -I ~/fltk-1.3.3 *.cpp `fltk-config --cxxflags --ldflags --use-cairo` -o lab

*/
Fl_Input* pizza; //definition
Fl_Input* address;
Fl_Input* driver;
Fl_Output* watch;
Fl_Text_Buffer* buff;
Fl_Text_Buffer* cbuff;
Fl_Text_Buffer* dbuff;
Fl_Text_Display* orderQ;
Fl_Text_Display* cookedQ;
Fl_Text_Display* driverQ;

int main ()
{
    Fl_Cairo_Window cw(400,300); //width and height of the window
    cw.label("Pizza Deliveries");//title of your window
    //cw.color(FL_BLUE);
    
    pizza = new Fl_Input(180,20,100,20, "Pizza:");
    pizza->labelcolor(FL_BLUE);
    
    address = new Fl_Input(180,40,100,20, "Address:");
    address->labelcolor(FL_BLUE);
    
    driver = new Fl_Input(180,60,100,20, "Driver:");
    driver->labelcolor(FL_BLUE);
    
    watch = new Fl_Output(70,20,60,20, "seconds:");
    
    buff = new Fl_Text_Buffer();
    orderQ = new Fl_Text_Display(50,100,100,100,"Order Q");
    orderQ->buffer(buff);
    
    cbuff = new Fl_Text_Buffer();
    cookedQ = new Fl_Text_Display(150,100,100,100,"Cooked Q");
    cookedQ->buffer(cbuff);

    dbuff = new Fl_Text_Buffer();
    driverQ = new Fl_Text_Display(250,100,100,100,"Driver Q");
    driverQ->buffer(dbuff);
    
    Fl_Button b(280,35,50,20, "Order");
    b.callback((Fl_Callback*)order_cb);
    
    Fl_Button a(280,60,50,20, "Add");
    a.callback((Fl_Callback*)driver_cb);
    cw.show();
    Fl::add_timeout(1,timer);
    return Fl::run();
    }
