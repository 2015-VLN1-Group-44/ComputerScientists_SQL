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

    vector<Scientist> sort(QString order);
    vector<Scientist> search(QString search_arg, QString column);

    Scientist find_from_id(int scientist_id);
    void edit_entry(QString column, QString insert, int id);
    void read_input();
    vector <string> connected_computers(int id);
    friend class Interface;
    void delete_id(int id);

private:
    Repository scientist_repo;
};

#endif // SCIENTIST_SERVICE_H
