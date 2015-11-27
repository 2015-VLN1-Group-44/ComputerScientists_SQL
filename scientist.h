#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
using namespace std;

const int date_format = 3;

class Scientist
{
public:
    Scientist();
    Scientist(string fn, string ln, bool g, int *db, int *dd);
    friend ostream& operator << (ostream& out, Scientist sc);
private:
    string first_name;
    string last_name;
    bool gender;
    int date_birth[date_format];
    int date_death[date_format];
};

#endif // SCIENTIST_H
