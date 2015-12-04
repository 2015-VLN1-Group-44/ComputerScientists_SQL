#include "interface.h"
#include "constants.h"
#include "constants.h"

Interface::Interface()
{
}

/* Bool breytan quit er false á meðan ekki er búið að velja quit möguleikann
 * Exit bool breytan tekur gildi úr föllunum fyrir undirvalmyndir, þau skila
 * false ef ekki er búið að velja exit inni í þeim, og þær undirvalmyndir keyra
 * þá aftur.
 */
bool Interface::start_menu()
{
    int selection = 0;
    bool quit, exit;
    string f; // strengur til að lesa inn filename
    cout << constants::MENU_DELIMITER << endl;
    cout << "1. Add Scientists to list\t";
    cout << "3. Search list\t\t\t";
    cout << "0. Quit" << endl;
    cout << "2. Display list of Scientists\t";
    cout << "4. Save list to .txt file"  << endl;
    cout << "Enter selection: ";
    cin >> selection;
    switch (selection)
    {
        case 1:

            do
            {
                exit = add_menu();
            } while (!exit);
            quit = false;
            break;
        case 2:
            do
            {
                exit = list_menu();
            } while (!exit);
            quit = false;
            break;
        case 3:
            do
            {
                exit = search_menu();
            } while (!exit);
            quit = false;
            break;
        case 4:
            cout << "Input filename: ";
            cin >> f;
            f += ".txt";
            scientist_service.save_file(f);
            quit = false;
            break;
        case 0:
            quit = true;
            break;
        default:
            cout << endl;
            cout << selection << " is not a valid menu item.\n";
            quit = false;
            break;
    }
    return quit;
}

bool Interface::add_menu()
{
    int select;
    bool exit = false;
    string n;
    cout << constants::MENU_DELIMITER << endl;
    cout << "1. Read from .txt file\t\t";
    cout << "2. Add Scientist manually\t";
    cout << "0. Main menu" << endl << constants::SELECTION_PROMPT;
    cin >> select;
    switch(select)
    {
        case 1:
            cout << "Input filename: ";
            cin >> n;
            n += ".txt";
            scientist_service.load_file(n);
            break;
        case 2:
            scientist_service.read_input();
            break;
        case 0:
            exit = true;
            break;
        default:
            cout << constants::SELECTION_NOT_VALID << endl;
            break;
    }
    return exit;
}

bool Interface::list_menu()
{
    bool exit = false;
    int select;

    cout << constants::MENU_DELIMITER << endl;
    cout << "1. Display list\t\t\t";
    cout << "4. Sort list by date of death\t";
    cout << "0. Main menu" << endl;
    cout << "2. Sort list by name\t\t";
    cout << "5. Sort list by gender" << endl;
    cout << "3. Sort list by date of birth\t";
    cout << "6. Reverse order" << endl;
    cout << constants::SELECTION_PROMPT;
    cin >> select;
    switch(select)
    {
        case 1:
            print_header();
            cout << scientist_service;
            break;
        case 2:
            scientist_service.sort_name();
            cout << "List sorted by name." << endl;
            break;
        case 3:
            scientist_service.sort_birth();
            cout << "List sorted by date of birth." << endl;
            break;
        case 4:
            scientist_service.sort_death();
            cout << "List sorted by date of death." << endl;
            break;
        case 5:
            scientist_service.sort_gender();
            cout << "List sorted by gender." << endl;
            break;
        case 6:
            scientist_service.reverse_order();
            cout << "List reversed." << endl;
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
    int select;
    unsigned int found_index;
    string name, line;
    bool found, valid_date;
    bool exit = false;
    QDate sdate;
    QString date;

    cout << constants::MENU_DELIMITER << endl;
    cout << "1. Search by first name\t\t";
    cout << "3. Search by date of birth\t";
    cout << "0. Main menu" << endl;
    cout << "2. Search by last name\t\t";
    cout << "4. Search by date of death" << endl;
    cout << "Enter selection: ";
    cin >> select;
    switch (select)
    {
        case 1:
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            found = search_first(found_index, name);
            exit = true;
            break;
        case 2:
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            found = search_last(found_index, name);
            exit = true;
            break;
        case 3:
            cout << "Enter date of birth (dd/mm/yyyy): ";
            cin.ignore();
            getline(cin, line);
            date = QString::fromStdString(line);
            sdate = QDate::fromString(date, constants::DATE_FORMAT);
            valid_date = sdate.isValid();
            if (valid_date)
            {
                found = search_birth(found_index, sdate);
            }
            else
            {
                found = valid_date;
            }
            exit = true;
            break;
        case 4:
            cout << "Enter date of death (dd/mm/yyyy): ";
            cin.ignore();
            getline(cin, line);
            date = QString::fromStdString(line);
            sdate = QDate::fromString(date, constants::DATE_FORMAT);
            valid_date = sdate.isValid();
            if (valid_date)
            {
                found = search_death(found_index, sdate);
            }
            else
            {
                found = valid_date;
            }
            exit = true;
        break;
        case 0:
            exit = true;
            found = true;
            return exit;
        default:
            cout << constants::SELECTION_NOT_VALID << endl;
            found = false;
            break;
    }
    if (found)
    {
        found_menu(found_index);
        exit = false;
    }
    if (!found && exit) // Val löglegt en ekkert fundið
    {
        cout << "No entries found." << endl;
        exit = false;
        char adding;
        bool legal_choice;
        do
        {
            cout << "Do you wish to add this person to the list of computer scientists(y/n)? " << endl;
            getline(cin, line);
            adding = line[0];
            if (tolower(adding) == 'y')
            {
                scientist_service.read_input();
                exit = true;
                legal_choice = true;
            }
            else if (adding == 'n' || adding == 'N')
            {
                exit = true;
                legal_choice = true;
            }
            else
            {
                cout << constants::SELECTION_NOT_VALID << endl;
                legal_choice = false;
            }
            } while (!legal_choice);
    }
    return exit;
}

bool Interface::search_first(unsigned int& found_i, string n)
{
    bool found = false;
    for (unsigned int i = 0; i < scientist_service.size(); i++)
    {
        if (n == scientist_service.data[i].get_first())
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
    for (unsigned int i = 0; i < scientist_service.size(); i++)
    {
        if (n == scientist_service.data[i].get_last())
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
    for (unsigned int i = 0; i < scientist_service.size(); i++)
    {
        if (b == scientist_service.data[i].get_birth())
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
    for (unsigned int i = 0; i < scientist_service.size(); i++)
    {
        if (d == scientist_service.data[i].get_death())
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
    cout << constants::MENU_DELIMITER << endl;
    print_header();
    cout << scientist_service.data[i];
    cout << "1. Edit entry" << endl;
    cout << "2. Remove entry" << endl;
    cout << "0. Search menu" << endl;
    cout << constants::SELECTION_PROMPT;
    cin >> select;
    switch (select)
    {
        case 1:
            edit_menu(i);
            valid = true;
            break;
        case 2:
            scientist_service.data.erase(scientist_service.data.begin() + (i));
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
        cout << constants::SELECTION_NOT_VALID << endl;
        found_menu(i);
    }
}

void Interface::edit_menu(unsigned int i)
{
    int select;
    string n, line;
    char g;
    QString date;
    QDate d, current;
    current = QDate::currentDate(); // Sækir daginn í dag úr klukkunni
    bool exit = false;
    cout << constants::MENU_DELIMITER << endl;
    cout << "1. Edit first name" << endl;
    cout << "2. Edit last name" << endl;
    cout << "3. Edit gender" << endl;
    cout << "4. Edit date of birth" << endl;
    cout << "5. Edit date of death" << endl;
    cout << "0. Search menu" << endl;
    cout << constants::SELECTION_PROMPT;
    cin >> select;
    switch (select)
    {
        case 1:
            cout << "Enter new first name: ";
            cin.ignore();
            getline(cin, n);
            scientist_service.data[i].set_first(n);
            print_header();
            cout << scientist_service.data[i];
            break;
        case 2:
            cout << "Enter new last name: ";
            cin.ignore();
            getline(cin, n);
            scientist_service.data[i].set_last(n);
            print_header();
            cout << scientist_service.data[i];
            break;
        case 3:
            cout << "Enter gender: ";
            cin.ignore();
            getline(cin, line);
            g = line[0];
            if (g == 'm' || g == 'M')
                scientist_service.data[i].set_gender(1);
            else if (g == 'f' || g == 'F')
                scientist_service.data[i].set_gender(0);
            else
                cout << "Not a valid gender." << endl;
            print_header();
            cout << scientist_service.data[i];
            break;
        case 4:
            cout << "Enter date of birth (dd/mm/yyyy): ";
            cin.ignore();
            getline(cin, line);
            date = QString::fromStdString(line);
            d = QDate::fromString(date, constants::DATE_FORMAT);
            if (!d.isValid())
            {
                cout << "Not a valid date." << endl;
            }
            else if (scientist_service.data[i].get_death() < d)
            {
                cout << "Date of birth after date of death. Please correct." << endl;
            }
            else if (current < d)
            {
                cout << "Date of birth after current date. Please correct." << endl;
            }
            else
            {
                scientist_service.data[i].set_birth(d);
                print_header();
                cout << scientist_service.data[i];
            }
            break;
        case 5:
            cout << "Enter date of death (dd/mm/yyyy): ";
            cin.ignore();
            getline(cin, line);
            date = QString::fromStdString(line); // breytir inputinu í QString
            d = QDate::fromString(date, constants::DATE_FORMAT); // breytir inputi í QDate
            if (!d.isValid())
            {
                cout << "Not a valid date." << endl;
            }
            else if (d < scientist_service.data[i].get_birth())
                cout << "Date of death before date of birth. Please correct." << endl;
            else if (current < d)
            {
                cout << "Date of death after current date. Please correct." << endl;
            }
            else
            {
                scientist_service.data[i].set_death(d);
                print_header();
                cout << scientist_service.data[i];
            }
            break;
        case 0:
            exit = true;
            break;
        default:
            cout << constants::SELECTION_NOT_VALID << endl;
            break;
    }
    if (!exit)
    {
        edit_menu(i);
    }
}

void Interface::print_header()
{
    const int MAX_NAME = 36;
    cout << "Name" << string(MAX_NAME, ' ') << "Gender\tDoB\t\tDoD\n";
    cout << constants::MENU_DELIMITER << endl;
}
