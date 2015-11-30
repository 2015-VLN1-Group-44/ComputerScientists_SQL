#include "interface.h"

Interface::Interface()
{

}

bool Interface::start_menu()
{
    int selection = 0;
    bool valid;
    //system("CLS");
    cout << endl;
    cout << "1. Add Scientists to list" << endl;
    cout << "2. Display List of Scientists" << endl;
    cout << "3. quit" << endl;
    cout << "Enter Selection: ";
    cin >> selection;
    switch (selection)
    {
        case 1:
            bool legal;
            do
            {
                legal = add_menu();
            }while (!legal);
            valid = true;
            break;
        case 2:
            cout << our_scientists;
            valid = true;
            break;
        case 3:
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
    cout << "0. Cancel" << endl << "Selection: ";
    cin >> select;
    switch(select)
    {
        case 1:
            cout << "TBA";
            valid = true;
            break;
        case 2:
            our_scientists.read_input();
            valid = true;
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
