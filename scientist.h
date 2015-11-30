#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
#include <QDate>
#include <fstream>

using namespace std;

const int date_format = 3;

class Scientist
{
public:
    Scientist();
    Scientist(string fn, string ln, bool g, QDate b, QDate d);

    string get_first();
    string get_last();
    bool get_gender();
    int get_birth_day();
    int get_birth_month();
    int get_birth_year();
    int get_death_day();
    int get_death_month();
    int get_death_year();
    QDate get_birth();
    QDate get_death();

    Scientist& operator = (Scientist other);
    friend ostream& operator << (ostream& out, Scientist sc);
    friend class Database;
private:
    string first_name;
    string last_name;
    bool gender;
    QDate birth;
    QDate death;
};

#endif // SCIENTIST_H
