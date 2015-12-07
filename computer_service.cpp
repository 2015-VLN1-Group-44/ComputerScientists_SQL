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
