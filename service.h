#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "scientist.h"
#include "repository.h"

using namespace std;

class Service : public Scientist
{
public:
    Service();
    Service(vector<Scientist> &d);
    unsigned int size();
    void sort_name();
    void sort_birth();
    void sort_death();
    void sort_gender();
    void reverse_order();

    void load_file(string file);
    void read_input();
    void save_file(string filename);

    friend bool name_order(Scientist n1, Scientist n2);
    friend bool death_order(Scientist n1, Scientist n2);
    friend bool gender_order(Scientist n1, Scientist n2);
    friend class Interface;
    friend ostream& operator << (ostream& out, Service d);

private:
    vector<Scientist> data;
    Repository scientist_repo;

};

#endif // SERVICE_H
