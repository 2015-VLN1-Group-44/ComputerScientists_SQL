#include <iostream>
#include <algorithm>
#include <string>
#include "database.h"
#include <fstream> 
#include "interface.h"

using namespace std;

void menu();

int main()
{
    QDate birth(1815, 12, 10);
    QDate death(1852, 11, 27); // Fæðingar- og dánardagur fyrir Ödu
    Interface implement_test;
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
    bool menu_input;
    do
    {
        menu_input = implement_test.start_menu();
    }while (!menu_input);

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

