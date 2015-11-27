#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
using namespace std;

const int date_format = 3;

class Scientist
{
public:
    Scientist();
    Scientist(string fn, string ln, bool g, int db[date_format], int dd[date_format]);
    Scientist(const Scientist& scientist_object); // Copy constructor
    friend ostream& operator << (ostream& out, Scientist sc);
    friend class Database;
private:
    string first_name;
    string last_name;
    bool gender;
    int date_birth[date_format];
    int date_death[date_format];
};

#endif // SCIENTIST_H
