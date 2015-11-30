#include <iostream>
#include <algorithm>
#include <string>
#include "database.h"
#include <fstream> 

using namespace std;

void menu();

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

    // Búa til instance af database úr vectornum
    Database data1(first_test);
    cout << "Test prent á Database: " << endl;
    cout << data1;

    cout << endl << "Test sort" << endl;
    data1.sort_death();
    cout << data1;

    data1.read_input();

    cout << data1;



    menu();


    return 0;

}

void menu()
{
    int selection = 0;
    //system("CLS");
    cout << endl;
    cout << "1. New Scientist" << endl;
    cout << "2. List of Scientists" << endl;
    cout << "3. quit" << endl;
    cout << "Enter Selection: ";
    cin >> selection;
    switch (selection)
    {
        case 1:
        cout << "New Scientist";
        break;
        case 2:
        cout << "List of Scientists";
        break;
        case 3:
        cout << "Quit";
        //exit(1);
        break;

        default:
        system("CLS");
        cout << endl;
        cout <<selection << " is not a valid menu item.\n";
        menu();
    }
}

