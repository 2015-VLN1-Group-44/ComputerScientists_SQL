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

// Skilar true ef 2 Scientist
bool death_order(Scientist n1, Scientist n2)
{
    bool d = false;
    if (n1.get_death() < n2.get_death())
    {
        d = true;
    }
    return d;
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
