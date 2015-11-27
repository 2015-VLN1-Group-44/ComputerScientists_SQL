#include <iostream>
#include "scientist.h"

using namespace std;

Scientist::Scientist()
{
}

// Constructor með argumentum
Scientist::Scientist(string fn, string ln, bool g, int db[date_format], int dd[date_format]){
    first_name = fn;
    last_name = ln;
    gender = g;
    for (int i = 0; i < date_format; i++)
    {
        date_birth[i] = db[i];
        date_death[i] = dd[i];
    }
}

// Copy constructor
Scientist::Scientist(const Scientist& scientist_object)
{
    first_name = scientist_object.first_name;
    last_name = scientist_object.last_name;
    gender = scientist_object.gender;
    for (int i = 0; i < date_format; i++)
    {
        date_birth[i] = scientist_object.date_birth[i];
        date_death[i] = scientist_object.date_death[i];
    }
}

// Operator overload til að prenta instance af klasanum
ostream& operator << (ostream& out, Scientist sc)
{
    out << sc.first_name << " " << sc.last_name << endl;
    if (sc.gender)
    {
        out << "Male" << endl;
    }
    else
        out << "Female" << endl;
    out << "Date of death: ";
    for (int i = 0; i < date_format; i++)
    {
        out << sc.date_death[i] << "/";
    }
    out << endl << "Date of birth: ";
    for (int i = 0; i < date_format; i++)
    {
        out << sc.date_birth[i] << "/";
    }
    out << endl;
    return out;
}
