#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <QString>
#include <QDate>
#include "service.h"
#include <fstream> 
#include <sstream>
#include "constants.h"
#include "repository.h"

using namespace std;

Service::Service()
{
}

Service::Service(vector<Scientist>& d)
{
    for (unsigned int i = 0; i < d.size(); i++)
    {
        data.push_back(d[i]);
    }
}

// Nokkur föll sem gera samanburð á tveimur elementum, skila true ef í réttri röð
bool name_order(Scientist n1, Scientist n2)
{
    bool order = false;
    if (n1.get_last() < n2.get_last())
    {
        order = true;
    }
    else if (n1.get_last() == n2.get_last() && n1.get_first() <= n2.get_first())
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
    if (n1.get_gender() < n2.get_gender())
    {
        g = true;
    }
    return g;
}

// Sort föll úr C++ library
void Service::sort_name()
{
    sort(data.begin(), data.end(), name_order);
}

void Service::sort_birth()
{
    sort(data.begin(), data.end(), birth_order);
}

void Service::sort_death()
{
    sort(data.begin(), data.end(), death_order);
}

void Service::sort_gender()
{
    sort(data.begin(), data.end(), gender_order);
}

void Service::reverse_order()
{
    reverse(data.begin(), data.end());
}

void Service::load_file(string file)
{
    data = scientist_repo.read_file(file);
}

// Les upplýsingar frá notanda
void Service::read_input()
{
    Scientist temp;
    char cgender, answer;
    string line;
    QDate in_date, current;
    current = QDate::currentDate(); // sækir daginn í dag í system-klukkuna
    QString date;
    bool valid_date, deceased, valid;
    cout << "Input first name(s): ";
    cin.ignore();                //varð að setja ignore til að miðjunafnið fari með. Ingvi
    getline(cin, temp.first_name);
    cout << "Input last name: ";
    getline(cin, temp.last_name);

    do
    {
        cout << "Input gender (M/F): ";
        getline(cin, line);
        cgender = line[0];
        switch(tolower(cgender))
        {
            case 'm':
                temp.gender = true;
                valid = true;
                break;
            case 'f':
                temp.gender = false;
                valid = true;
                break;
            default:
                cout << "Invalid gender. Please correct." << endl;
                break;
        }
    } while (!valid);
    do
    {
        cout << "Input date of birth (dd/mm/yyyy): ";
        getline(cin, line);
        date = QString::fromStdString(line);    // breytir innlestri í QString
        in_date = QDate::fromString(date, constants::DATE_FORMAT);  // innlestur => dags.
        valid_date = in_date.isValid();
        if(!valid_date)
        {
            cout << "Date is not valid." << endl;
        }
        else if (current < in_date)
        {
            cout << "Date of birth after current date. Please correct" << endl;
            valid_date = false;
        }
    } while (!valid_date);
    temp.birth = in_date;

    do
    {
        cout << "Is this person living (y/n)?" << endl;
        getline(cin, line);
        answer = line[0];
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
    } while ( !(tolower(answer) == 'y' || tolower(answer) == 'n'));
    if (deceased)
    {
        cin.ignore();  // grípur newline á undan
        do
        {
            cout << "Input date of death (dd/mm/yyyy): ";
            getline(cin, line);
            date = QString::fromStdString(line); // breytir innlestri í QString
            in_date = QDate::fromString(date, constants::DATE_FORMAT); // breytir innlestri í dags.
            valid_date = in_date.isValid();  // testar hvort dagsetning sé gild
            if(!valid_date)
            {
                cout << "Date is not valid." << endl;
            }
            else if (in_date < temp.birth) // fæðing ekki eftir dauða
            {
                cout << "Date of death before date of birth. Please correct." << endl;
                valid_date = false;
            }
            else if (current < in_date)
            {
                cout << "Date of death after today's date. Please correct." << endl;
                valid_date = false;
            }
        } while (!valid_date);
    }
    if (!deceased)
    {
        in_date.setDate(0, 0, 0);
    }
    temp.death = in_date;
    data.push_back(temp);
}

void Service::save_file(string filename)
{
    scientist_repo.print_to_file(filename, data);
}

unsigned int Service::size()
{
    return data.size();
}

ostream& operator << (ostream& out, Service d)
{
    for (unsigned int i = 0; i < d.size(); i++)
    {
        out << d.data[i]; // notar overload << virkjann í Scientist
    }
    return out;
}

