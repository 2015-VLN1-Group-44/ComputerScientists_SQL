#include <iostream>
#include "scientist.h"
#include <string>

using namespace std;

Scientist::Scientist()
{
}

// Constructor með argumentum
Scientist::Scientist(string fn, string ln, bool g, QDate b, QDate d){
    first_name = fn;
    last_name = ln;
    gender = g;
    birth = b;
    death = d;
}

string Scientist::get_first()
{
    return first_name;
}
string Scientist::get_last()
{
    return last_name;
}
int Scientist::get_birth_day()
{
    return birth.day();
}
int Scientist::get_birth_month()
{
    return birth.month();
}
int Scientist::get_birth_year()
{
    return birth.year();
}
int Scientist::get_death_day()
{
    return death.day();
}
int Scientist::get_death_month()
{
    return death.month();
}
int Scientist::get_death_year()
{
    return death.year();
}

// Operator overload til að prenta instance af klasanum
ostream& operator << (ostream& out, Scientist sc)
{
    out << "Name: " << sc.first_name << " " << sc.last_name << endl;
    out << "Gender: ";
    if (sc.gender)
    {
        out << "Male" << endl;
    }
    else
        out << "Female" << endl;

    out << "Date of Birth: " << endl;
    out << sc.birth.day() << "/" << sc.birth.month() << "/";
    out << sc.birth.year() << endl;
    out << "Date of Death: " << endl;
    out << sc.death.day() << "/" << sc.death.month() << "/";
    out << sc.death.year() << endl;
    return out;
}

