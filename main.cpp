#include <iostream>
#include "database.h"

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

    cout << "Test prent á Scientist: " << endl;
    //Búa til instance af Scientist til að prófa klasann
    Scientist first("Ada", "Lovelace", 0, dob, dod);
    Scientist second("Alan", "Turing", 1, dob, dod);
    // Prenta Scientist klasann
    cout << first << endl;

    // búa til vector til að lesa inn í Database object
    vector<Scientist> first_test;
    first_test.push_back(first);
    first_test.push_back(second);
    Database data1(first_test);
    cout << "Test prent á Database: " << endl;
    cout << data1;
    return 0;
}

