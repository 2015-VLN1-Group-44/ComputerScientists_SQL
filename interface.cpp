#include "interface.h"

Interface::Interface()
{
}

Interface::Interface(vector<Scientist> v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        list_scientists.data.push_back(v[i]);
    }
}

bool Interface::start_menu()
{
    int selection = 0;
    bool valid, legal;
    //system("CLS");
    cout << endl;
    cout << "1. Add Scientists to list" << endl;
    cout << "2. Display List of Scientists" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter selection: ";
    cin >> selection;
    switch (selection)
    {
        case 1:

            do
            {
                legal = add_menu();
            }while (!legal);
            valid = false;
            break;
        case 2:
            do
            {
                legal = list_menu();
            }while (!legal);
            valid = false;
            break;
        case 0:
            cout << "Quit";
            valid = true;
            //exit(1);
            break;

        default:
            system("CLS");
            cout << endl;
            cout << selection << " is not a valid menu item.\n";
            valid = false;
    }
    return valid;
}

bool Interface::add_menu()
{
    int select;
    bool valid = false;
    cout << "1. Read from file" << endl;
    cout << "2. Add Scientist manually" << endl;
    cout << "0. Main menu" << endl << "Selection: ";
    cin >> select;
    switch(select)
    {
        case 1:
            cout << "TBA";
            break;
        case 2:
            list_scientists.read_input();
            break;
        case 0:
            valid = true;
            break;
        default:
            cout << select << " is not a valid menu item." << endl;
            break;
    }
    return valid;
}

bool Interface::list_menu()
{
    bool valid = false;
    int select;
    string f; // strengur til að lesa inn filename
    cout << "1. Display list" << endl;
    cout << "2. Sort list by name" << endl;
    cout << "3. Sort list by date of birth" << endl;
    cout << "4. Sort list by date of death" << endl;
    cout << "5. Sort list by gender" << endl;
    cout << "6. Save list" << endl;
    cout << "0. Main menu" << endl;
    cout << "Enter selection: ";
    cin >> select;
    switch(select)
    {
        case 1:
            cout << list_scientists;
        break;
        case 2:
            list_scientists.sort_name();
            cout << "List sorted by name." << endl;
        break;
        case 3:
            list_scientists.sort_birth();
            cout << "List sorted by date of birth." << endl;
        break;
        case 4:
            list_scientists.sort_death();
            cout << "List sorted by date of death." << endl;
        break;
        case 5:
            list_scientists.sort_gender();
            cout << "List sorted by gender." << endl;
        break;
        case 6:
            cout << "Input filename: ";
            cin >> f;
            f += ".txt";
            list_scientists.print_to_file(f);
        break;
        case 0:
            valid = true;
        break;
        default:
            cout << select << " is not a valid menu item." << endl;
        break;
    }
    return valid;
}
