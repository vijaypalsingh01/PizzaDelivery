#include "lab.h"
 
void timer(void*)
{
    //std::cout << "1 sec" << std::endl;
    static int s = 0; static int m = 0;
    std::ostringstream oss; 
    
    s++; if (s == 59) {s=0; m++;}
    oss << std::setfill('0');
    oss << std::setw(2) << m << ":" << std::setw(2) << s;
    watch->value(oss.str().c_str());
    
    Fl::repeat_timeout(1,timer); //repeats after every second
 
}
 
