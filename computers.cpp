#include "computers.h"


Computers::Computers()
{
}

Computers::Computers(string n, int y, bool b, computer_type ct, int id, bool act)
{
    name = n;
    year = y;
    built = b;
    comp_t = ct;
    this->id = id;
    active = act;
}

string Computers::get_name()
{
    return name;
}

int Computers::get_year()
{
    return year;
}

bool Computers::get_built()
{
    return built;
}

enum computer_type Computers::get_type()
{
    return comp_t;
}

int Computers::get_id()
{
    return id;
}

void Computers::set_name(string n)
{
    name = n;
}

void Computers::set_year(int y)
{
    year = y;
}

void Computers::set_built(bool b)
{
    built = b;
}

void Computers::set_type(computer_type ct)
{
    comp_t = ct;
}

ostream& operator << (ostream& out, Computers comp)
{
    out << comp.name << "\t";
    if (comp.built)
    {
        out << comp.year << "\t";
    }
    else
    {
        out << "Not built\t";
    }
    // tékk tékk
    if (comp.comp_t == 1)
    {
        out << "Mechanical";
    }
    else if (comp.comp_t == 2)
    {
        out << "Transistor";
    }
    else
    {
        out << "Electronic";
    }
    out << endl;
    return out;
}
