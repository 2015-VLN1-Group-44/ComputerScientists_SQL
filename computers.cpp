#include "computers.h"
#include <string>


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
    int comp_name_length = comp.name.size();    //búa til pláss fyrir nafn

    out << comp.name;
    if (comp_name_length < constants::MAX_COMP_NAME_LENGTH )  //Fyllir línuna ef nafnið er undir max_name_length
        {
            //name_length = constants::MAX_NAME_LENGTH - name_length;
            out << string(constants::MAX_COMP_NAME_LENGTH - comp_name_length , ' ');
        }
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
