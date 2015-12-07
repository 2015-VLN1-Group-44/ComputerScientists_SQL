#ifndef SCIENTIST_SERVICE_H
#define SCIENTIST_SERVICE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "scientist.h"
#include "repository.h"

using namespace std;

class Scientist_service : public Scientist
{
public:
    Scientist_service();
    Scientist_service(vector<Scientist> &d);
    unsigned int size();
    void initialize(QString db_name);
    vector<Scientist> sort(QString order);
    vector<Scientist> search(QString search_arg, QString column);

    Scientist find_from_id(int scientist_id);

    void edit_entry(QString column, QString insert, int id);

    void read_input();

    friend class Interface;
    friend ostream& operator << (ostream& out, Scientist_service d);

private:
    vector<Scientist> data;
    Repository scientist_repo;

};

#endif // SCIENTIST_SERVICE_H
