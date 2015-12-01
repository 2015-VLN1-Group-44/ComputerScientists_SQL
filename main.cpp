#include <iostream>
#include <algorithm>
#include <string>
#include "database.h"
#include <fstream> 
#include "interface.h"

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

    first_test.push_back(second);
    first_test.push_back(first);

    Interface implement_test(first_test);

    bool quit;
    // Keyrir start menu - start_menu skilar false áður en búið er að gera quit
    do
    {
        quit = implement_test.start_menu();
    }while (!quit);

    return 0;

}
