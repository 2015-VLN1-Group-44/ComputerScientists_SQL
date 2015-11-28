#include <iostream>
#include "database.h"

using namespace std;

int main()
{
    QDate birth(1815, 12, 10);
    QDate death(1852, 11, 27); // Fæðingar- og dánardagur fyrir Ödu

    // Búa til instance af Scientist til að prófa klasann
    Scientist first("Ada", "Lovelace", 0, birth, death);
    cout << "Test prent á Scientist: " << endl;
    // Prenta Scientist klasann
    cout << first << endl;

    QDate b(1912, 6, 23);
    QDate d(1954, 6, 7);
    Scientist second("Alan", "Turing", 1, b, d);


    // búa til vector til að lesa inn í Database object
    vector<Scientist> first_test;
    first_test.push_back(first);
    first_test.push_back(second);

    // Búa til instance af database úr vectornum
    Database data1(first_test);
    cout << "Test prent á Database: " << endl;
    cout << data1;
    return 0;
}

