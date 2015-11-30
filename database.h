#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <scientist.h>

using namespace std;

class Database : public Scientist
{
public:
    Database();
    Database(vector<Scientist> &d);
    unsigned int size();
    void sort_name();
    void sort_birth();
    void sort_death();
    void sort_gender();
    void read_input();
    void print_to_file();


    friend bool name_order(Scientist n1, Scientist n2);
    friend bool death_order(Scientist n1, Scientist n2);
    friend bool gender_order(Scientist n1, Scientist n2);
    friend class Interface;
    friend ostream& operator << (ostream& out, Database d);

private:
    vector<Scientist> data;
};

#endif // DATABASE_H
