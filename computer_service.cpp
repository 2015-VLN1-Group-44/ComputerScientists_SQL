#include "computer_service.h"

Computer_service::Computer_service()
{
}

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

vector<string> Computer_service::connected_scientists(int id)
{
    QString command = QString(constants::SCIENTIST_JOIN.arg(id));

    vector<string> scientist_names = computer_repo.connected(command, "lastname");

    return scientist_names;
}
