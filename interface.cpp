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
    bool quit, exit;
    cout << string(20, '-') << endl;
    cout << "1. Add Scientists to list" << endl;
    cout << "2. Display List of Scientists" << endl;
    cout << "3. Search list" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter selection: ";
    cin >> selection;
    switch (selection)
    {
        case 1:

            do
            {
                exit = add_menu();
            }while (!exit);
            quit = false;
            break;
        case 2:
            do
            {
                exit = list_menu();
            }while (!exit);
            quit = false;
            break;
        case 3:
            do
            {
                exit = search_menu();
            }while (!exit);
            quit = false;
            break;
        case 0:
            cout << "Quit";
            quit = true;
            break;

        default:
            cout << endl;
            cout << selection << " is not a valid menu item.\n";
            quit = false;
    }
    return quit;
}

bool Interface::add_menu()
{
    int select;
    bool exit = false;
    string n;
    cout << string(20, '-') << endl;
    cout << "1. Read from .txt file" << endl;
    cout << "2. Add Scientist manually" << endl;
    cout << "0. Main menu" << endl << "Selection: ";
    cin >> select;
    switch(select)
    {
        case 1:
            cout << "Input filename: ";
            cin >> n;
            n += ".txt";
            list_scientists.read_file(n);
            break;
        case 2:
            list_scientists.read_input();
        break;
        case 0:
            exit = true;
            break;
        default:
            cout << select << " is not a valid menu item." << endl;
            break;
    }
    return exit;
}

bool Interface::list_menu()
{
    bool exit = false;
    int select;
    string f; // strengur til að lesa inn filename
    cout << string(20, '-') << endl;
    cout << "1. Display list" << endl;
    cout << "2. Sort list by name" << endl;
    cout << "3. Sort list by date of birth" << endl;
    cout << "4. Sort list by date of death" << endl;
    cout << "5. Sort list by gender" << endl;
    cout << "6. Save list to .txt file" << endl;
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
            exit = true;
        break;
        default:
            cout << select << " is not a valid menu item." << endl;
        break;
    }
    return exit;
}

bool Interface::search_menu()
{
    int select, day, month, year;
    unsigned int found_index;
    string name;
    char stop;
    bool found, valid_date;
    bool exit = false;
    QDate sdate;
    cout << string(20, '-') << endl;
    cout << "1. Search by first name" << endl;
    cout << "2. Search by last name" << endl;
    cout << "3. Search by date of birth" << endl;
    cout << "4. Search by date of death" << endl;
    cout << "0. Main menu" << endl;
    cout << "Enter selection: ";
    cin >> select;
    switch (select)
    {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            found = search_first(found_index, name);
            exit = true;
        break;
        case 2:
            cout << "Enter name: ";
            cin >> name;
            found = search_last(found_index, name);
            exit = true;
        break;
        case 3:
            cout << "Enter date of birth (dd/mm/yyyy): ";
            cin >> day >> stop >> month >> stop >> year;
            valid_date = sdate.setDate(year, month, day);
            if (valid_date)
            {
                found = search_birth(found_index, sdate);
            }
            else
                found = valid_date;
            exit = true;
        break;
        case 4:
            cout << "Enter date of death (dd/mm/yyyy): ";
            cin >> day >> stop >> month >> stop >> year;
            valid_date = sdate.setDate(year, month, day);
            if (valid_date)
            {
                found = search_death(found_index, sdate);
            }
            else
                found = valid_date;
            exit = true;
        break;
        case 0:
            exit = true;
            found = true;
            return exit;
        default:
            cout << "Invalid selection." << endl;
            found = false;
        break;

    }
    if(found)
    {
        found_menu(found_index);
        exit = false;
    }
    if (!found && exit) // Val löglegt en ekkert fundið
    {
        cout << "No entries found." << endl;
        exit = false;
    }
    return exit;
}

bool Interface::search_first(unsigned int& found_i, string n)
{
    bool found = false;
    for(unsigned int i = 0; i < list_scientists.size(); i++)
    {
        if(n == list_scientists.data[i].get_first())
        {
            found = true;
            found_i = i;
        }
    }
    return found;
}

bool Interface::search_last(unsigned int& found_i, string n)
{
    bool found = false;
    for(unsigned int i = 0; i < list_scientists.size(); i++)
    {
        if(n == list_scientists.data[i].get_last())
        {
            found = true;
            found_i = i;
        }
    }
    return found;
}

bool Interface::search_birth(unsigned int& found_i, QDate b)
{
    bool found = false;
    for(unsigned int i = 0; i < list_scientists.size(); i++)
    {
        if(b == list_scientists.data[i].get_birth())
        {
            found = true;
            found_i = i;
        }
    }
    return found;
}


bool Interface::search_death(unsigned int& found_i, QDate d)
{
    bool found = false;
    for(unsigned int i = 0; i < list_scientists.size(); i++)
    {
        if(d == list_scientists.data[i].get_death())
        {
            found = true;
            found_i = i;
        }
    }
    return found;
}


void Interface::found_menu(unsigned int i)
{
    int select;
    bool valid;
    cout << "Found entry: " << endl;
    cout << string(20, '-') << endl;
    cout << list_scientists.data[i];
    cout << "1. Edit entry" << endl;
    cout << "2. Remove entry" << endl;
    cout << "0. Search menu" << endl;
    cout << "Enter selection: ";
    cin >> select;
    switch(select)
    {
        case 1:
            edit_menu(i);
            valid = true;
        break;
        case 2:
            list_scientists.data.erase(list_scientists.data.begin() + (i));
            valid = true;
        break;
        case 0:
            valid = true;
        break;
        default:
            valid = false;
        break;
    }
    if (!valid)
    {
        cout << "Invalid menu item." << endl;
        found_menu(i);
    }
}

void Interface::edit_menu(unsigned int i)
{
    int select, day, month, year;
    string n;
    char g, stop;
    QDate d;
    bool exit = false;
    cout << string(20, '-') << endl;
    cout << "1. Edit first name" << endl;
    cout << "2. Edit last name" << endl;
    cout << "3. Edit gender" << endl;
    cout << "4. Edit date of birth" << endl;
    cout << "5. Edit date of death" << endl;
    cout << "0. Search menu" << endl;
    cout << "Enter selection: ";
    cin >> select;
    switch (select)
    {
        case 1:
            cout << "Enter new first name: ";
            cin >> n;
            list_scientists.data[i].set_first(n);
        break;
        case 2:
            cout << "Enter new last name: ";
            cin >> n;
            list_scientists.data[i].set_last(n);
        break;
        case 3:
            cout << "Enter gender: ";
            cin >> g;
            if (g == 'm' || g == 'M')
                list_scientists.data[i].set_gender(1);
            else
                list_scientists.data[i].set_gender(0);
        break;
        case 4:
            cout << "Enter date of birth (dd/mm/yyyy): ";
            cin >> day >> stop >> month >> stop >> year;
            exit = d.setDate(year, month, day);
            if (exit)
            {
                list_scientists.data[i].set_birth(d);
                exit = false;
            }
        break;
        case 5:
            cout << "Enter date of death (dd/mm/yyyy): ";
            cin >> day >> stop >> month >> stop >> year;
            exit = d.setDate(year, month, day);
            if (exit)
            {
                list_scientists.data[i].set_death(d);
                exit = false;
            }
        break;
        case 0:
            exit = true;
        break;
        default:
            cout << "Invalid menu item." << endl;
        break;
    }
    if(!exit)
    {
        edit_menu(i);
    }
}
