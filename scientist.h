#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
#include <QDate>
#include <fstream>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string fn, string ln, bool g, QDate b, QDate d, bool l);
    Scientist(string fn, string ln, bool g, QDate b, QDate d, bool l, int id_num, bool act);

    void set_first(string n);
    void set_last(string n);
    void set_birth(QDate b);
    void set_death(QDate d);
    void set_gender(bool g);
    void set_living(bool a);

    string get_first();
    string get_last();
    bool get_gender();
    bool get_living();
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
    bool living;
    int id;
    bool active;
};

#endif // SCIENTIST_H
