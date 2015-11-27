#include <iostream>
#include "scientist.h"

using namespace std;

Scientist::Scientist()
{
}

// Constructor með argumentum

Scientist::Scientist(string fn, string ln, bool g, int *db, int *dd){
    first_name = fn;
    last_name = ln;
    gender = g;
    for (int i = 0; i < date_format; i++)
    {
        date_birth[i] = db[i];
        date_death[i] = dd[i];
    }
}

ostream& operator << (ostream& out, Scientist sc)
{
    out << sc.first_name << " " << sc.last_name << endl;
    if (sc.gender)
    {
        out << "Male" << endl;
    }
    else
        out << "Female" << endl;
    cout << "Date of birth: ";
    for (int i = 0; i < date_format; i++)
    {
        out << sc.date_birth[i] << "/";
    }
    out << endl;
    out << "Date of death: ";
    for (int i = 0; i < date_format; i++)
    {
        out << sc.date_death[i] << "/";
    }
    out << endl;
    return out;
}
