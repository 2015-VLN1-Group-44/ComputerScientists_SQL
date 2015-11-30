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
    bool start_menu();
    bool add_menu();


private:
    string filename;
    Database our_scientists;
};


#endif // INTERFACE_H
