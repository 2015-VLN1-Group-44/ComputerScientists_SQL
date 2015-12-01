#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <QString>
#include <QDate>
#include "database.h"
#include <fstream> 
#include <sstream>

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
    char cgender, answer;
    int day, month, year;
    char stop;
    QDate in_date;
    bool valid_date, deceased;
    cout << "Input first name(s): ";
    cin.ignore();                       //varð að setja git.ignore til að miðjunafnið fari með. Ingvi
    std::getline(cin, temp.first_name);
    //cin >> temp.first_name;           //má eyða ef allt keyrir rétt. Ingvi
    cout << "Input last name: ";
    std::getline(cin, temp.last_name);
    //cin >> temp.last_name;            //má eyða ef allt keyrir rétt. Ingvi
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
    do
    {
        cout << "Input date of birth (dd/mm/yyyy): ";
        cin >> day >> stop >> month >> stop >> year;
        in_date.setDate(year, month, day);
        valid_date = in_date.isValid();
        if(!valid_date)
        {
            cout << "Date is not valid." << endl;
        }
    }while(!valid_date);
    temp.birth = in_date;
    do
    {
        cout << "Is this person living (y/n)?" << endl;
        cin >> answer;
        switch (tolower(answer))
        {
            case 'y':
                deceased = false;
                temp.living = true;
            break;
            case 'n':
                deceased = true;
            break;
            default:
            break;
        }
    }while( !(answer == 'y' || answer == 'n'));
    if (deceased)
    {
        do
        {
            cout << "Input date of death (dd/mm/yyyy): ";
            cin >> day >> stop >> month >> stop >> year;
            in_date.setDate(year, month, day);
            valid_date = in_date.isValid();
            if(!valid_date)
            {
                cout << "Date is not valid." << endl;
            }
        }while(!valid_date);
    }
    if (!deceased)
    {
        in_date.setDate(0, 0, 0);
    }
    temp.death = in_date;
    data.push_back(temp);
}

void Database::read_file(string filename)
{
    Scientist temp;
    ifstream in_file;
    string line;
    char g;
    QDate birth, death;
    QString date, format;
    format = "d.M.yyyy";
    in_file.open(filename.c_str());
    if (in_file.fail())
    {
        cout << "Unable to open file" << endl;
    }
    while (getline(in_file, line))
    {
        temp.first_name = line;
        getline(in_file, line);
        temp.last_name = line;
        getline(in_file, line);
        date = QString::fromStdString(line);
        temp.birth = QDate::fromString(date, format);
        getline(in_file, line);
        date = QString::fromStdString(line);
        temp.death = QDate::fromString(date, format);
        if(temp.death.isValid() == false)
        {
            temp.living = true;
        }
        else
        {
            temp.living = false;
        }
        getline(in_file, line);
        g = line[0];
        if(g == 'M' || g == 'm')
        {
            temp.gender = 1;
        }
        else
            temp.gender = 0;
        data.push_back(temp);
    }
    in_file.close();
}

void Database::print_to_file(string filename)
{
    ofstream out_file;
    out_file.open(filename.c_str());
    for (unsigned int i = 0; i < size(); i++)
    {
        out_file << data[i].get_first()<< endl;
        out_file << data[i].get_last() << endl;
        out_file << data[i].get_birth().day() << "." << data[i].get_birth().month();
        out_file << "." << data[i].get_birth().year() << endl;
        if(!living)
        {
            out_file << data[i].get_death().day() << "." << data[i].get_death().month() << ".";
            out_file << data[i].get_death().year() << endl;
        }
        else
        {
            out_file << "0.0.0" << endl;
        }
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
