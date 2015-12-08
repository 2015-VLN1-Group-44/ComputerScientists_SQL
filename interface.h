#ifndef INTERFACE_H
#define INTERFACE_H

#include "constants.h"
#include "scientist_service.h"
#include "computer_service.h"
#include <iostream>
#include <string>

using namespace std;

class Interface
{
public:
    Interface();
    Interface(vector<Scientist> v);
    void start_menu();
    bool add_menu();
    bool list_menu();
    void computer_list_menu();
    bool search_menu();
    void computer_search_menu();
    void found_menu(vector<Scientist> found);
    void edit_menu(int edit_id);
    void print_header();
    // spyr notanda í hvaða átt hann vill raða
    bool asc_desc();
private:
    Scientist_service scientist_service;
    Computer_service computer_service;
};


#endif // INTERFACE_H
