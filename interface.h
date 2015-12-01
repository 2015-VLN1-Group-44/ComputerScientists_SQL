#ifndef INTERFACE_H
#define INTERFACE_H

#include "database.h"
#include <iostream>
#include <string>

using namespace std;

class Interface
{
public:
    Interface();
    Interface(vector<Scientist> v);
    bool start_menu();
    bool add_menu();
    bool list_menu();
private:
    Database list_scientists;
};


#endif // INTERFACE_H
