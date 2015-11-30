#include <iostream>
#include <vector>
#include "database.h"
#include <fstream> 

using namespace std;

Database::Database()
{
}

Database::Database(vector<Scientist>& d)
{
    for (unsigned int i = 0; i < d.size(); i++)
    {
        data.push_back(d[i]);
    }
}

unsigned int Database::size()
{
    return data.size();
}

ostream& operator << (ostream& out, Database d)
{
    for (unsigned int i = 0; i < d.size(); i++)
    {
        out << d.data[i];
    }
    return out;
}

bool Database::name_ordered(string f1, string l1, string f2, string l2)
{
    bool ordered = false;
    if(l1 < l2)
    {
        ordered = true;
    }
    else if(l1 == l2 && f1 < f2)
    {
        ordered = true;
    }
    return ordered;
}
