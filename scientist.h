#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
#include <QDate>
using namespace std;

const int date_format = 3;

class Scientist
{
public:
    Scientist();
    Scientist(string fn, string ln, bool g, QDate b, QDate d);
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
