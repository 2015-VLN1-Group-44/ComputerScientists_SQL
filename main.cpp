#include <QCoreApplication>
#include <iostream>
#include "scientist.h"

using namespace std;

int main()
{
    int dob[date_format], dod[date_format];
    for (int i = 0; i < date_format; i++)
    {
        dob[i] = 10 * i;
        dod[i] = 11 * i;
    }
    Scientist first("Ada", "Lovelace", 0, dob, dod);
    cout << first;
    return 0;
}

