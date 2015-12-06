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

    vector<Scientist> sort_name(bool asc);
    vector<Scientist> sort_birth(bool asc);
    vector<Scientist> sort_death(bool asc);
    vector<Scientist> sort_gender(bool asc);
    void reverse_order();
    
    bool search_first(vector<int>& found_i, string n);
    bool search_last(vector<int>& found_i, string n);
    bool search_birth(vector<int>& found_i, QDate b);
    bool search_death(vector<int>& found_i, QDate d);

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
