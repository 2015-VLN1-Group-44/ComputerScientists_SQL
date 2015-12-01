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
    bool search_menu();
    bool search_first(unsigned int& found_i, string n);
    bool search_last(unsigned int& found_i, string n);
    bool search_birth(unsigned int& found_i, QDate b);
    bool search_death(unsigned int& found_i, QDate d);
    void found_menu(unsigned int i);
    void edit_menu(unsigned int i);
private:
    Database list_scientists;
};


#endif // INTERFACE_H
