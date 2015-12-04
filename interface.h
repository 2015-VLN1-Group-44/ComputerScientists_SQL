#ifndef INTERFACE_H
#define INTERFACE_H

#include "service.h"
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
    bool search_menu();

    void found_menu(vector<int> found_i);
    void edit_menu(unsigned int i);
    void print_header();
private:
    Service scientist_service;
};


#endif // INTERFACE_H
