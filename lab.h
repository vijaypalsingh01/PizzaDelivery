#include "config.h"
#include <FL/Fl_Cairo_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <unistd.h>

//declaration of pizza pointer and other pointers which will be used by FLTK
extern Fl_Input* pizza; 
extern Fl_Input* address;
extern Fl_Input* driver;
extern Fl_Output* watch;
extern Fl_Text_Buffer* buff;
extern Fl_Text_Buffer* cbuff;
extern Fl_Text_Buffer* dbuff;
extern Fl_Text_Display* driverQ;
extern Fl_Text_Display* orderQ;
extern Fl_Text_Display* cookedQ;


/**  \brief This is the callback function to order a pizza
    void pointers not used
    return void
*/
void order_cb(void*,void*);

/**  \brief This is the callback function to add drivers manually
    void pointers not used
    return void
*/
void driver_cb(void*);


/**  \brief This is the callback function called from the order_cb function which cooks the pizza
    void pointer not used
    return void
*/
void cook_cb(void*);


/**  \brief This is the callback function called from the cook_cb function which assigns and send drivers out for delivery after the pizza is cooked
    void pointers not used
    return void
*/
void delivery_cb(void*);

/**  \brief This is the callback function called fron delivery which adds the driver back in the queue after they deliver the pizza
    void pointers not used
    return void
*/
void addBackDr_cb(void*);

/**  \brief This is a time function which keeps track of the time
    void pointers not used
    return void
*/
void timer(void*);

/**  
    \brief struct named ORDER which will have the name of the pizza and the address for delivery
*/
struct ORDER
{
    std::string info;
    std::string addr;
    };
    
/**  
    \brief struct NODE that will be used to make linked list  
*/
struct NODE 
{   ORDER info;
    NODE *next;
    };
    
class LLQUEUE 
{ 
    private:
        NODE *front;
        NODE *rear;
    public:
    
/**  
    \brief constructor of the queue class which sets the value of the private functions to 0
*/
        LLQUEUE() {front=rear=0;};
/**  
    \brief destructor of the queue class which removes all the data from the queue
*/
        ~LLQUEUE();
/**  
    \brief insert adds data into the queue
    \param [in] info is the data that will be added into the queue
    \return boolean indication if the data was inserted successfully
*/
        bool Insert (ORDER &info);
/**  
    \brief removed data from the queue
    \param [out] info is the data that will be removed from the queue
    \return boolean indication if the data was removed successfully
*/
        bool Remove (ORDER &info);
/**  
    \brief checks if the queue is empty
    \return boolean indication if the queue is empty or not
*/
        bool isEmpty() {return (front ==0);}
/**  
    \brief gives the user all the data that is present in the queue
    \return string containing all the data that is stored in the queue
*/
        std::string getQcontent();
    };

const int BUFSIZE = 256;

class RBQUEUE 
{
    private:
        std::string buf[BUFSIZE];
        int front;
        int rear;
        int nextIndex(int index)
        {
            if(++index == BUFSIZE)
            index = 0;
            return index;
            }
        public:
/**  
    \brief constructor of the ring buffer queue which sets the private data members to 0
*/
        RBQUEUE() {front = rear = 0;}
 /**  
    \brief destructor of the ring buffer queue which deletes all the data in the queue
*/   
        ~RBQUEUE() {}
/**  
    \brief insert adds data into the queue
    \param [in] s is the data that will be added into the queue
    \return boolean indication if the data was inserted successfully
*/
        bool Insert (std::string s);
/**  
    \brief removed data from the queue
    \param [out] s is the data that will be removed from the queue
    \return boolean indication if the data was removed successfully
*/
        bool Remove (std::string &s);
/**  
    \brief checks if the queue is empty
    \return boolean indication if the queue is empty or not
*/
        bool isEmpty() {return (front == rear);}
/**  
    \brief checks if the queue is full
    \return boolean indication if the queue is full or not
*/
        bool isFull() {return (nextIndex(rear) == front);}
/**  
    \brief gives the user all the data that is present in the queue
    \return string containing all the data that is stored in the queue
*/
        std::string getRQcontents();
    };
    
    
extern ORDER ord;
extern LLQUEUE o;
extern LLQUEUE c;
extern RBQUEUE d;
extern RBQUEUE currD;

