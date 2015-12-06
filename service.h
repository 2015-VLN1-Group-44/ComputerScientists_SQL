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

    vector<Scientist> sort(QString order);
    void reverse_order();
    
    bool search_first(vector<int>& found_i, string n);
    bool search_last(vector<int>& found_i, string n);
    bool search_birth(vector<int>& found_i, QDate b);
    bool search_death(vector<int>& found_i, QDate d);

    vector<Scientist> search(QString search_arg, QString column);

    Scientist find_from_id(int scientist_id);

    void edit_entry(QString column, QString insert, int id);
    void edit_gender(QString column, bool g, int id);

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
