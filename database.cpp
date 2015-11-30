#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
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

bool name_order(Scientist n1, Scientist n2)
{
    bool order = false;
    if (n1.get_last() < n2.get_last())
    {
        order = true;
    }
    else if(n1.get_last() == n2.get_last() && n1.get_first() <= n2.get_first())
    {
        order = true;
    }
    return order;
}

bool birth_order(Scientist n1, Scientist n2)
{
    bool b = false;
    if (n1.get_birth() < n2.get_birth())
    {
        b = true;
    }
    return b;
}

bool death_order(Scientist n1, Scientist n2)
{
    bool d = false;
    if (n1.get_death() < n2.get_death())
    {
        d = true;
    }
    return d;
}

bool gender_order(Scientist n1, Scientist n2)
{
    bool g = false;
    if (n1.get_gender() > n2.get_gender())
    {
        g = true;
    }
    return g;
}


void Database::sort_name()
{
    sort(data.begin(), data.end(), name_order);
}

void Database::sort_birth()
{
    sort(data.begin(), data.end(), birth_order);
}

void Database::sort_death()
{
    sort(data.begin(), data.end(), death_order);
}

void Database::sort_gender()
{
    sort(data.begin(), data.end(), gender_order);
}


// Les upplýsingar frá notanda
void Database::read_input()
{
    Scientist temp;
    char cgender;
    int day, month, year;
    char stop;
    cout << "Input first name(s): ";
    cin >> temp.first_name;
    cout << "Input last name: ";
    cin >> temp.last_name;
    cout << "Input gender (M/F): ";
    cin >> cgender;
    switch(tolower(cgender))
    {
        case 'm':
            temp.gender = true;
            break;
        case 'f':
            temp.gender = false;
            break;
        default:
            break;
    }
    cout << "Input date of birth (dd/mm/yyyy): ";
    cin >> day >> stop >> month >> stop >> year;
    QDate birthd(year, month, day);
    temp.birth = birthd;
    cout << "Input date of death (dd/mm/yyyy): ";
    cin >> day >> stop >> month >> stop >> year;
    QDate deathd(year, month, day);
    temp.death = deathd;
    data.push_back(temp);
}

void Database::print_to_file(string filename)
{
    ofstream out_file;
    out_file.open(filename.c_str());
    for (unsigned int i = 0; i < size(); i++)
    {
        out_file << data[i].get_first()<< " " << data[i].get_last() << " ";
        out_file << data[i].get_birth_day() << "." << data[i].get_birth_month();
        out_file << "." << data[i].get_birth_year() << " ";
        out_file << data[i].get_death_day() << "." << data[i].get_death_month() << ".";
        out_file << data[i].get_death_year() << " ";
        if(data[i].get_gender())
            out_file << "M" << endl;
        else
            out_file << "F" << endl;
    }
    out_file.close();
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
