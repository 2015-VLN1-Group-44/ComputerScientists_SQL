#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include "scientist.h"

using namespace std;

class Database
{
public:
    Database();
    Database(vector<Scientist> &d);
    unsigned int size();

    bool name_order(Scientist n1, Scientist n2);

    friend ostream& operator << (ostream& out, Database d);

private:
    vector<Scientist> data;
};

#endif // DATABASE_H
