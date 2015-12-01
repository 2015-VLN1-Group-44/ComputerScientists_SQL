#include <iostream>
#include "scientist.h"
#include <string>
#include <fstream>

using namespace std;

Scientist::Scientist()
{
}

// Constructor með argumentum
Scientist::Scientist(string fn, string ln, bool g, QDate b, QDate d, bool l)
{
    first_name = fn;
    last_name = ln;
    gender = g;
    birth = b;
    death = d;
    living = l;
}

void Scientist::set_first(string n)
{
    first_name = n;
}

void Scientist::set_last(string n)
{
    last_name = n;
}

void Scientist::set_birth(QDate b)
{
    birth = b;
}

void Scientist::set_death(QDate d)
{
    death = d;
    if (death.isValid())
    {
        living = false;
    }
}

void Scientist::set_gender(bool g)
{
    gender = g;
}

string Scientist::get_first()
{
    return first_name;
}
string Scientist::get_last()
{
    return last_name;
}
bool Scientist::get_gender()
{
    return gender;
}

QDate Scientist::get_birth()
{
    return birth;
}

QDate Scientist::get_death()
{
    return death;
}


Scientist& Scientist::operator = (Scientist other)
{
    first_name = other.first_name;
    last_name = other.last_name;
    gender = other.gender;
    birth = other.birth;
    death = other.death;
    living = other.living;
    return *this;
}


// Operator overload til að prenta instance af klasanum
ostream& operator << (ostream& out, Scientist sc)
{
    out << string(20, '-') << endl;
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
    if (!sc.living)
    {
        out << "Date of Death: " << endl;
        out << sc.death.day() << "/" << sc.death.month() << "/";
        out << sc.death.year() << endl;
    }
    else
        out << sc.first_name << " is alive and well." << endl;
    return out;
}
