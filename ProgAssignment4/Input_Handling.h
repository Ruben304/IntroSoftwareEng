#ifndef input_handling_h
#define input_handling_h
#include <iostream>
#include <string>

using namespace std;

class Invalid_Input{
    public: 
        Invalid_Input(string in_ptr) : msg_ptr (in_ptr) {}

        const string msg_ptr;

    private:
        Invalid_Input();
};


#endif