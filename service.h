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

    vector<Scientist> search(QString search_arg, QString column);

    Scientist find_from_id(int scientist_id);

    void edit_entry(QString column, QString insert, int id);

    void read_input();

    friend class Interface;
    friend ostream& operator << (ostream& out, Service d);

private:
    vector<Scientist> data;
    Repository scientist_repo;

};

#endif // SERVICE_H
