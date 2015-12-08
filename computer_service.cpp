#include "computer_service.h"

Computer_service::Computer_service()
{
}

//void Computer_service::initialize(QString db_name)
//{
//    computer_repo.connect_db(db_name);
//}

vector<Computers> Computer_service::sort(QString sort_order)
{
    QString command = QString(constants::COMPUTERS_ORDER.arg(sort_order));
    return computer_repo.open_computer_db(command);
}

vector<Computers> Computer_service::search(QString column, QString search_arg)
{
    QString command = QString(constants::COMPUTERS_SEARCH.arg(column).arg(search_arg));
    return computer_repo.open_computer_db(command);
}

void Computer_service::edit_entry (QString column, QString argument, int id)
{
    QString command = QString(constants::COMPUTERS_EDIT.arg(column).arg(argument).arg(id));
    computer_repo.open_computer_db(command);
}

Computers Computer_service::from_id(int id)
{
    QString command = QString(constants::COMPUTER_FROM_ID.arg(id));
    return computer_repo.open_computer_db(command)[0];
}

//vector<string> Computer_service::connected_scientists(int id)
//{
//    QString command = QString(constants::CONNECTED_SCIENTIST_ID.arg(id));
//    vector<int> scientist_id = computer_repo.connected(command, "scientist_id");
//    vector<string> scientist_names;

//    for (unsigned int i = 0; i < scientist_id.size(); i++)
//    {
//        vector<Scientist> temp = computer_repo.connected(constants::SCIENTIST_FROM_ID.arg(scientist_id[i]));
//    }
//    return scientist_names;
//}
