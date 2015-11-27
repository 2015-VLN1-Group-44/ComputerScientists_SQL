#include <QCoreApplication>
#include <iostream>
#include "scientist.h"

using namespace std;

int main()
{
    // Test fylki fyrir dagsetningar, fyllt með bulli
    int dob[date_format], dod[date_format];
    for (int i = 0; i < date_format; i++)
    {
        dob[i] = 10 * i;
        dod[i] = 11 * i;
    }

    //Búa til instance af Scientist til að prófa klasann
    Scientist first("Ada", "Lovelace", 0, dob, dod);

    // Prenta klasann
    cout << first;
    return 0;
}

