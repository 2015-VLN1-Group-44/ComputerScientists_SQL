#include "interface.h"



Interface::Interface()
{
}

/* Bool breytan quit er false á meðan ekki er búið að velja quit möguleikann
 * Exit bool breytan tekur gildi úr föllunum fyrir undirvalmyndir, þau skila
 * false ef ekki er búið að velja exit inni í þeim, og þær undirvalmyndir keyra
 * þá aftur.
 */
void Interface::start_menu()
{
    int selection = 0;
    bool quit, exit;
    // tempbreyta til að prófa útprent
    vector<Computers> temp;
//    scientist_service.initialize(constants::DATABASE_NAME);
//    computer_service.initialize(constants::DATABASE_NAME);
    do
    {
        cout << constants::MENU_DELIMITER << endl;
        cout << "1. Add Scientists to list\t";
        cout << "3. Search scientists\t\t";
        cout << "0. Quit" << endl;
        cout << "2. Display list of scientists\t";
        cout << "4. Display list of computers" << endl;
        cout << "5. Search computers" << endl;
        cout << endl;
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
            computer_list_menu();
            quit = false;
            break;
        case 5:
            computer_search_menu();
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
    } while (!quit);
}

bool Interface::add_menu()
{
    scientist_service.read_input();
    return true;
}

bool Interface::list_menu()
{
    bool exit = false;
    bool asc;
    int select;
    vector<Scientist> data;

    cout << constants::MENU_DELIMITER << endl;
    cout << "1. Sort list by name\t\t";
    cout << "3. Sort list by date of death\t";
    cout << "0. Main menu" << endl;
    cout << "2. Sort list by date of birth\t";
    cout << "4. Sort list by gender" << endl;
    cout << "5. Remove/delete entry" << endl;
    cout << endl;
    cout << constants::SELECTION_PROMPT;
    cin >> select;
    switch(select)
    {
        case 1:
            asc = asc_desc();
            if (asc)
            {
                data = scientist_service.sort("lastname, firstname");
            }
            else
                data = scientist_service.sort("lastname DESC, firstname DESC");
            print_header();
            for (unsigned int i = 0; i < data.size(); i++)
            {
                cout << data[i];
            }
            break;
        case 2:
            if ( (asc = asc_desc()) )
            {
            data = scientist_service.sort("birth");
            }
            else
                data = scientist_service.sort("birth DESC");
            print_header();
            for (unsigned int i = 0; i < data.size(); i++)
            {
                cout << data[i];
            }
            break;
        case 3:
            if ((asc = asc_desc()))
            {
            data = scientist_service.sort("death");
            }
            else
                data = scientist_service.sort("death DESC");
            print_header();
            for (unsigned int i = 0; i < data.size(); i++)
            {
                cout << data[i];
            }
            break;
        case 4:
            if ((asc = asc_desc()))
            {
            data = scientist_service.sort("gender");
            }
            else
                data = scientist_service.sort("gender DESC");
            print_header();
            for (unsigned int i = 0; i < data.size(); i++)
            {
                cout << data[i];
            }
            break;
        case 5:
             edit_remove();
        case 0:
            exit = true;
            break;
        default:
            cout << select << " is not a valid menu item." << endl;
            break;
    }
    return exit;
}

void Interface::computer_list_menu()
{
    bool exit = false;
    do
    {
        bool asc;
        int select;
        vector<Computers> data;

        cout << constants::MENU_DELIMITER << endl;
        cout << "1. Sort list by name\t\t";
        cout << "3. Sort list by type\t\t";
        cout << "0. Main menu" << endl;
        cout << "2. Sort list by date built" << endl;
        cout << endl;
        cout << constants::SELECTION_PROMPT;
        cin >> select;
        switch(select)
        {
            case 1:
                asc = asc_desc();
                if (asc)
                {
                    data = computer_service.sort("name");
                }
                else
                    data = computer_service.sort("name DESC");
                for (unsigned int i = 0; i < data.size(); i++)
                {
                    cout << data[i];
                }
                break;
            case 2:
                if ( (asc = asc_desc()) )
                {
                data = computer_service.sort("built_year");
                }
                else
                    data = computer_service.sort("built_year DESC");
                print_header();
                for (unsigned int i = 0; i < data.size(); i++)
                {
                    cout << data[i];
                }
                break;
            case 3:
                if ((asc = asc_desc()))
                {
                data = computer_service.sort("type");
                }
                else
                    data = computer_service.sort("type DESC");
                print_header();
                for (unsigned int i = 0; i < data.size(); i++)
                {
                    cout << data[i];
                }
                break;
            case 0:
                exit = true;
                break;
            default:
                cout << select << " is not a valid menu item." << endl;
                break;
        }
    } while (!exit);
}

bool Interface::search_menu()
{
    int select;
    string name, line;
    bool found;
    bool exit = false;
    QDate sdate;
    QString date, name_search;
    vector<int> found_index;
    vector<Scientist> found_scientists;

    cout << constants::MENU_DELIMITER << endl;
    cout << "1. Search by first name\t\t";
    cout << "3. Search by date of birth\t";
    cout << "0. Main menu" << endl;
    cout << "2. Search by last name\t\t";
    cout << "4. Search by date of death" << endl;
    cout << "Enter selection: ";
    cout << endl;
    cin >> select;
    switch (select)
    {
        case 1:
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            name_search = QString::fromStdString(name);
            found_scientists = scientist_service.search(name_search, "firstname");

            if (!found_scientists.empty())
            {
                found = true;
            }
            else
                found = false;
            exit = true;
            break;
        case 2:
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            name_search = QString::fromStdString(name);
            found_scientists = scientist_service.search(name_search, "lastname");

            if (!found_scientists.empty())
            {
                found = true;
            }
            else
                found = false;
                exit = true;
            break;
        case 3:
            cout << "Enter date of birth 'yyyy-mm-dd' (month/day optional): ";
            cin.ignore();
            getline(cin, line);
            date = QString::fromStdString(line);
            found_scientists = scientist_service.search(date, "birth");
            if (!found_scientists.empty())
            {
                found = true;
            }
            else
            {
                found = false;
            }
            exit = true;
            break;
        case 4:
            cout << "Enter date of death 'yyyy-mm-dd' (month/day optional): ";
            cin.ignore();
            getline(cin, line);
            date = QString::fromStdString(line);
            found_scientists = scientist_service.search(date, "death");
            if (!found_scientists.empty())
            {
                found = true;

            }
            else
            {
                found = false;
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
        found_menu(found_scientists);
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

void Interface::computer_search_menu()
{
    bool exit = false;
    do
    {
        int select;
        string name;
        int year, type;
        QString search_term;
        vector<Computers> found_computers;

        cout << constants::MENU_DELIMITER << endl;
        cout << "1. Search by name\t\t";
        cout << "3. Search by type\t\t";
        cout << "0. Main menu" << endl;
        cout << "2. Search by year built" << endl;
        cout << endl;
        cout << constants::SELECTION_PROMPT;
        cin >> select;
        switch (select)
        {
            case 1:
                cout << "Enter name: ";
                cin.ignore();
                getline (cin, name);
                search_term = QString::fromStdString(name);
                found_computers = computer_service.search("name", search_term);
            break;
            case 2:
                cout << "Enter year: ";
                cin >> year;
                search_term = QString::number(year);
                found_computers = computer_service.search("built_year", search_term);
            break;
            case 3:
                cout << "Choose search term." << endl;
                cout << "(1 for mechanical, 2 for transistor, 3 for electronic): ";
                cin >> type;
                search_term = QString::number(type);
                found_computers = computer_service.search("type", search_term);
            break;
            case 0:
                exit = true;
            break;
            default:
                cout << constants::SELECTION_NOT_VALID;
            break;
        }
        if (!found_computers.empty())
        {
           found_computers_menu(found_computers);
        }
        else
        {
            cout << "No entries found. Search again?" << endl;
        }
    } while (!exit);
}

void Interface::found_menu(vector<Scientist> found)
{
    int select;
    bool valid;
    cout << constants::FOUND << endl;
    cout << constants::MENU_DELIMITER << endl;
    print_header();
    for (unsigned int i = 0; i < found.size(); i++)
    {
        cout << "Entry " << i + 1 << ":" << endl;
        cout << found[i];
        cout << endl;
    }
    cout << "1. Edit entry" << endl;
    cout << "2. Remove entry" << endl;
    cout << "0. Search menu" << endl;
    cout << endl;
    cout << constants::SELECTION_PROMPT;
    cin >> select;
    switch (select)
    {
        case 1:
            do
            {
                cout << "Choose entry to edit (0 to cancel): ";
                cin >> select;
                if(select > 0 && select <= (int) found.size())
                {
                    edit_menu(found[select - 1].get_id());
                    valid = true;
                }
                else if (select == 0)
                {
                    valid = true;
                }
                else
                {
                    cout << constants::SELECTION_NOT_VALID << endl;
                    valid = false;
                }
            } while (!valid);
            break;
        case 2:
            do
            {
                cout << "Choose entry to delete (0 to cancel): ";
                cin >> select;
                if (select > 0 && select <= (int) found.size())
                {
                    valid = true;
                    scientist_service.edit_entry("active", "0", found[select - 1].get_id());
                }
                else if (select == 0)
                {
                    valid = true;
                }
                else
                    valid = false;
            } while (!valid);
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
        found_menu(found);
    }
}

void Interface::found_computers_menu(vector<Computers> found)
{
    int select;
    bool valid;
    cout << constants::FOUND << endl;
    cout << constants::MENU_DELIMITER << endl;
    for (unsigned int i = 0; i < found.size(); i++)
    {
        cout << "Entry " << i + 1 << ":" << endl;
        cout << found[i];
        cout << endl;
    }
    cout << "1. Edit entry" << endl;
    cout << "2. Remove entry" << endl;
    cout << "0. Search menu" << endl;
    cout << endl;
    cout << constants::SELECTION_PROMPT;
    cin >> select;
    switch (select)
    {
        case 1:
            do
            {
                cout << "Choose entry to edit (0 to cancel): ";
                cin >> select;
                if(select > 0 && select <= (int) found.size())
                {
                    edit_computers(found[select - 1]);
                    valid = true;
                }
                else if (select == 0)
                {
                    valid = true;
                }
                else
                {
                    cout << constants::SELECTION_NOT_VALID << endl;
                    valid = false;
                }
            } while (!valid);
            break;
        case 2:
            do
            {
                cout << "Choose entry to delete (0 to cancel): ";
                cin >> select;
                if (select > 0 && select <= (int) found.size())
                {
                    valid = true;
                    computer_service.edit_entry("active", "0", found[select - 1].get_id());
                }
                else if (select == 0)
                {
                    valid = true;
                }
                else
                {
                    valid = false;
                    cout << constants::SELECTION_NOT_VALID << endl;
                }
            } while (!valid);
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
        found_computers_menu(found);
    }
}


void Interface::edit_menu(int edit_id)
{
    int select;
    string line, n;
    char g;
    QString date, name;
    QDate b, d, current;
    current = QDate::currentDate(); // Sækir daginn í dag úr klukkunni
    bool exit = false;

    cout << constants::MENU_DELIMITER << endl;
    cout << scientist_service.find_from_id(edit_id);
    cout << "1. Edit first name" << endl;
    cout << "2. Edit last name" << endl;
    cout << "3. Edit gender" << endl;
    cout << "4. Edit date of birth" << endl;
    cout << "5. Edit date of death" << endl;
    cout << "0. Search menu" << endl;
    cout << endl;
    cout << constants::SELECTION_PROMPT;
    cin >> select;
    switch (select)
    {
        case 1:
            cout << "Enter new first name: ";
            cin.ignore();
            getline(cin, n);
            scientist_service.edit_entry("firstname", QString::fromStdString(n), edit_id);
            break;
        case 2:
            cout << "Enter new last name: ";
            cin.ignore();
            getline(cin, n);
            scientist_service.edit_entry("lastname", QString::fromStdString(n), edit_id);
            break;
        case 3:
            cout << "Enter gender: ";
            cin.ignore();
            getline(cin, line);
            g = line[0];
            if (g == 'm' || g == 'M')
            {
                scientist_service.edit_entry("gender", "1", edit_id);
            }

            else if (g == 'f' || g == 'F')
                scientist_service.edit_entry("gender", "0", edit_id);
            else
                cout << "Not a valid gender." << endl;
            break;
        case 4:
            cout << "Enter date of birth (dd/mm/yyyy): ";
            cin.ignore();
            getline(cin, line);
            date = QString::fromStdString(line); // breytir inputinu í QString
            b = QDate::fromString(date, constants::DATE_FORMAT); // breytir inputi í QDate
            date = b.toString(constants::IMPORT_DATE_FORMAT);
            if (!b.isValid())
            {
                cout << "Not a valid date." << endl;
            }
            else if (b > scientist_service.find_from_id(edit_id).get_death())
                cout << "Date of birth after date of death. Please correct." << endl;
            else if (current < b)
            {
                cout << "Date of birth after current date. Please correct." << endl;
            }
            else
            {
                scientist_service.edit_entry("birth", date, edit_id);
            }
            break;
        case 5:
            cout << "Enter date of death (dd/mm/yyyy): ";
            cin.ignore();
            getline(cin, line);
            date = QString::fromStdString(line); // breytir inputinu í QString
            d = QDate::fromString(date, constants::DATE_FORMAT); // breytir inputi í QDate
            date = d.toString(constants::IMPORT_DATE_FORMAT);

            if (!d.isValid())
            {
                cout << "Not a valid date." << endl;
            }
            else if (d < scientist_service.find_from_id(edit_id).get_birth())
                cout << "Date of death before date of birth. Please correct." << endl;
            else if (current < d)
            {
                cout << "Date of death after current date. Please correct." << endl;
            }
            else
            {
                scientist_service.edit_entry("death", date, edit_id);
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
        edit_menu(edit_id);
    }
}

void Interface::edit_computers(Computers c_edit)
{
    int select;
    string line;
    bool exit = false;
    int type;

    cout << constants::MENU_DELIMITER << endl;
    cout << c_edit;
    cout << "1. Edit name" << endl;
    cout << "2. Edit year built" << endl;
    cout << "3. Edit type" << endl;
    cout << "0. Search menu" << endl;
    cout << endl;
    cout << constants::SELECTION_PROMPT;
    cin >> select;
    switch (select)
    {
        case 1:
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, line);
            computer_service.edit_entry("name", QString::fromStdString(line), c_edit.get_id());
            break;
        case 2:
            cout << "Enter year: ";
            cin.ignore();
            getline(cin, line);
            computer_service.edit_entry("built_year", QString::fromStdString(line), c_edit.get_id());
            break;
        case 3:
            cout << "Enter type." << endl;
            cout << "(1 for mechanical, 2 for transistor, 3 for electronic): ";
            cin >> type;
            if (type == 1)
            {
                computer_service.edit_entry("type", "1", c_edit.get_id());
            }

            else if (type == 2)
            {
                computer_service.edit_entry("type", "2", c_edit.get_id());
            }
            else if (type == 3)
            {
                computer_service.edit_entry("type", "3", c_edit.get_id());
            }
            else
                cout << "Not a valid type." << endl;
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
        edit_computers(computer_service.from_id(c_edit.get_id()));
    }
}

void Interface::print_header()
{
    const int MAX_NAME = 36;
    cout << "Name" << string(MAX_NAME, ' ') << "Gender\tDoB\t\tDoD\n";
    cout << constants::MENU_DELIMITER << endl;
}

bool Interface::asc_desc()
{
    bool asc, valid;
    string command;
    do
    {
        int command = 0;
        cout << "\n1. Ascending\t";
        cout << "2. Descending" << endl;
        cout << "Enter selection ";
        cin >> command;
        cout << endl;

        switch (command)                    //Val fyrir Ascending/Descending
        {
            case 1:
                asc = true;
                valid = true;
            break;

            case 2:
                asc = false;
                valid = true;
            break;

            default:
                cout << constants::SELECTION_NOT_VALID << endl;
                valid = false;

        }
    } while (!valid);
    return asc;
}

bool Interface::edit_remove()
{
    vector <Scientist> d;
    int remove;
    int counter = 1;
    int id_del;
    d = scientist_service.sort("lastname, firstname");
    for(unsigned long i = 0; i < d.size(); i++)
    {
        cout << counter++ << "  " << d[i];
    }
    cout << endl;
    cout << "Choose the ID of the scientist you wish to remove from the list: ";
    cin >> remove;
    if(remove <= 0)
    {
        cout << endl;
        cout << "No scientist has the ID-number: " << remove << endl;
        return false;
    }
    else
    {
        id_del = d[remove - 1].get_id();
        computer_service.delete_id(id_del);
        cout << "Entry removed." << endl;
        return true;
    }
    return true;
}
